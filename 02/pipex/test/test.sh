#!/bin/bash
exec 2>/dev/null
mkdir test; cp pipex test; cd test;
# validation test
test_few_args() {
    local testname="$1"
	shift 
	touch errlog;
    ./pipex "$@" 2> errlog
    local actual_status=$?

    if [ "$actual_status" -ne 1 ]; then
        echo "$testname: failed (exit $actual_status, expected 1)"
        return
    fi
	if [ -s errlog ]; then
		echo "$testname: success"
	else
		echo "$testname: failed (message not found)"
		echo "--- stderr ---"
		cat errlog
	fi
}

echo "-----validation test-----"
test_few_args test_few_args0
test_few_args test_few_args1 file1
test_few_args test_few_args2 file1 "ls"
test_few_args test_few_args3 file1 "ls" "wc"

# general test

test(){
	touch infile; touch outfile1; touch outfile2; touch errlog1; touch errlog2;
    bash -c "
        bash -c \"$CMD1\" < infile | \
        bash -c \"$CMD2\" > outfile1
    " 2>errlog1
    local expected_status=${PIPESTATUS[1]}
	./pipex infile "$CMD1" "$CMD2" outfile2 2> errlog2
	local actual_status=$?
    if [ "$actual_status" -ne "$expected_status" ]; then
        echo "$1: failed (exit $actual_status, expected $expected_status)"
        return
    fi
	if diff outfile1 outfile2 > /dev/null; then
		echo "$1: success"
	else
		echo "$1: failed"
		diff outfile1 outfile2
	fi
}

echo "-----general test-----"
CMD1="cat"; CMD2="cat"
echo "hello world" > infile
test test1
CMD1="ls -a"; CMD2="cat"
test test2
CMD1="grep hello"; CMD2="wc -c"
echo -e "hello world\nbye world" > infile
test test3
CMD1="tr a-z A-Z"; CMD2="cat"
echo "hello pipex" > infile
test test4
CMD1="head -n 1"; CMD2="wc -w"
echo -e "a b c d\nx y z" > infile
test test5
CMD1="sort"; CMD2="uniq"
echo -e "banana\napple\nbanana\ncherry" > infile
test test6
CMD1="cat"; CMD2="grep 'a b'"
echo -e "a b\nb c\nc a\na b c" > infile
test test7
CMD1="cat"; CMD2="grep a\ b"
echo -e "a b\nb c\nc a\na b c" > infile
test test8

# invalid command test
echo "-----invalid command test-----"
CMD1="no_cmd"; CMD2="cat"
test test1
CMD1="cat"; CMD2="no_cmd" 
test test2
CMD1="   	"; CMD2="cat" # space and tab
test test3
CMD1="cat"; CMD2="   	" # space and tab
test test4
CMD1=""; CMD2="cat"
test test5
CMD1="cat"; CMD2=""
test test6
CMD1="x11vnc"; CMD2="ls"
test test7
CMD1="ls"; CMD2="x11vnc"; 
test test8

# invalid redirect test
compare_errlog() {
    local log1="$1" log2="$2"

    # 本文だけを改行区切り・ソート済みで取り出し、一致すれば OK
    diff -u \
        <(extract_msg <"$log1" | sort) \
        <(extract_msg <"$log2" | sort) \
        >/dev/null
}

test_invalid_files() {
    local testname="$1"

    # ---------- 参照パイプライン ----------
    bash -c "
        bash -c \"$CMD1\" < $INFILE | \
        bash -c \"$CMD2\" > $OUTFILE
    " 2>errlog1
    local expected_status=$?

    # ---------- pipex ----------
    ./pipex $INFILE "$CMD1" "$CMD2" $OUTFILE 2>errlog2
    local actual_status=$?

    # ---------- 判定 ----------
    if [ "$actual_status" -ne "$expected_status" ]; then
        echo "$testname: failed (exit $actual_status, expected $expected_status)"
        return
    fi
    if compare_errlog errlog1 errlog2; then
        echo "$testname: success"
    else
        echo "$testname: failed (stderr mismatch)"
        diff -u <(extract_msg <errlog1 | sort) <(extract_msg <errlog2 | sort)
    fi
}


echo "-----invalid redirect test-----"
echo "hello world" > infile;
# test_invalid_files1
CMD1="cat"; CMD2="cat";
INFILE="not_exist_file"; OUTFILE="outfile";
rm -f $INFILE; touch $OUTFILE;
test_invalid_files test_invalid_files1
# test_invalid_files2
INFILE="infile"; OUTFILE=not_exist_file;
rm -f $OUTFILE; touch $INFILE;
test_invalid_files test_invalid_files2
# test_invalid_files3
INFILE="unreadable_file"; OUTFILE=outfile;
touch unreadable_file; chmod 000 unreadable_file
test_invalid_files test_invalid_files3
# test_invalid_files4
CMD1="cat"; CMD2="cat infile";
INFILE="infile"; OUTFILE="unwritable_file";
touch unwritable_file; chmod 555 unwritable_file
test_invalid_files test_invalid_files4

# leak test
leak_test(){
    local testname="$1"
    shift
    local logfile="valgrind_$testname.log"

    valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all \
             --log-file="$logfile" ./pipex "$@"

    if grep -q "All heap blocks were freed -- no leaks are possible" "$logfile"; then
        echo "$testname: success"
    else
        echo "$testname: failed"
        echo "--- LEAK SUMMARY for $testname ---"
        awk '/LEAK SUMMARY:/,/^$/' "$logfile"
    fi
}
echo "-----memory leak test-----"
leak_test leak_test1 a
leak_test leak_test2 a a a a a
echo "hello world" > infile
leak_test leak_test3 infile cat cat outfile
echo -e "a b\nb c\nc a\na b c" > infile
echo "hello world" > infile
leak_test leak_test4 infile cat "grep 'a b'" outfile
leak_test leak_test5 infile no_cmd cat outfile
leak_test leak_test6 infile cat no_cmd outfile
leak_test leak_test7 infile "    " cat outfile
leak_test leak_test8 infile cat "    " outfile
leak_test leak_test9 infile "" cat outfile
leak_test leak_test10 infile cat "" outfile
leak_test leak_test11 infile x11vnc ls outfile
leak_test leak_test12 infile ls x11vnc outfile
rm -f not_exist_file;
leak_test leak_test13 not_exist_file cat cat outfile
touch unreadable_file; chmod 000 unreadable_file
leak_test leak_test14 unreadable_file cat cat outfile
touch unwritable_file; chmod 555 unwritable_file
leak_test leak_test15 infile cat cat unwritable_file


echo "-----end-----"
cd ..
