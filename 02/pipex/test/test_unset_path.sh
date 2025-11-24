#!/bin/bash

# ===============================================
# テスト環境の準備
# ===============================================

# テストに必要なパイプx実行ファイルがカレントディレクトリにあることを前提とします。
# 以前のテスト環境 (testディレクトリ) があれば、そこへ移動します。
if [ -d test ]; then
    cd test
fi

# ヘルパー関数: コマンドが見つからないエラーを検証する
test_unset() {
    local testname="$1"
    local infile="$2"
    local cmd1="$3"
    local cmd2="$4"
    local outfile="$5"
    
    # 標準エラー出力を errlog にリダイレクト
    # PATHを一時的にunsetしてpipexを実行
    (unset PATH; ./pipex "$infile" "$cmd1" "$cmd2" "$outfile") 2> errlog
    local actual_status=$?
    
    local expected_msg="command not found"

    echo "--- Test: $testname ---"

    # 1. 終了ステータスの検証 (期待値: 127)
    if [ "$actual_status" -ne 127 ]; then
        echo "$testname: ❌ FAILED (Exit $actual_status, Expected 127)"
        return
    fi

    # 2. エラーメッセージの検証 (期待値: 'command not found')
    if grep -q "$expected_msg" errlog; then
        echo "$testname: ✅ SUCCESS"
    else
        echo "$testname: ❌ FAILED (Message not found)"
        echo "--- Actual stderr ---"
        cat errlog
    fi
}

# ===============================================
# テストケースの実行
# ===============================================

echo "--- UNSET PATH TEST SUITE ---"

# 実行ファイルが一時的に必要なので作成 (中身は何でも良い)
echo "dummy" > infile_tmp
touch outfile_tmp

# Test 1: CMD1が見つからない
test_unset "unset_cmd1_not_found" "infile_tmp" "non_existent_ls" "wc" "outfile_tmp"

# Test 2: CMD2が見つからない
test_unset "unset_cmd2_not_found" "infile_tmp" "cat" "non_existent_wc" "outfile_tmp"

# Test 3: 両方のコマンドが見つからない
test_unset "unset_both_not_found" "infile_tmp" "grep_not" "wc_not" "outfile_tmp"

# Test 4: 絶対パスコマンドは実行可能か (PATHは関係ないはず)
# 注意: /bin/ls が存在しない環境では失敗する可能性があります
test_unset "unset_absolute_path" "infile_tmp" "/bin/ls" "wc" "outfile_tmp"
# 期待される結果: /bin/ls は PATH 不要なので成功し、終了ステータスは 0 または wc の結果になるはず

# ===============================================
# クリーンアップ
# ===============================================
rm -f infile_tmp outfile_tmp errlog

if [ -d test ]; then
    cd ..
fi

echo "--- TEST COMPLETE ---"
