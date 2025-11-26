#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int success)
{
    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG\n");
}

// 2つのテストを実行するメインテスト関数
void run_test(const char *test_name, const char *input_str)
{
    char *res1;
    char *res2;

    printf("--- Test Case: \"%s\" ---\n", input_str);
    res1 = ft_strdup(input_str);
    res2 = strdup(input_str);

    // 1. どちらもNULLではないか（メモリ確保成功か）
    if (res1 == NULL || res2 == NULL)
    {
        print_result("Allocation check", res1 == res2);
        free(res1);
        free(res2);
        printf("\n");
        return;
    }
    
    // 2. 文字列の内容が一致するか
    print_result("Content matches", strcmp(res1, res2) == 0);
    
    // 3. 元のポインタとは違う、新しいアドレスが返されているか
    print_result("Pointer is new", res1 != input_str && res2 != input_str);

    // 必ず確保したメモリを解放する
    free(res1);
    free(res2);
    printf("\n");
}

int main(void)
{
    printf("========= Test Cases for strdup =========\n\n");

    // --- テストケース1: 通常の文字列 ---
    run_test("Normal String", "Hello, World!");

    // --- テストケース2: 空文字列 ---
    run_test("Empty String", "");
    
    // --- テストケース3: 長い文字列 ---
    run_test("Long String", "This is a considerably longer string to test allocation.");

    // --- テストケース4: 無効な文字列 ---
    char *null_test = ft_strdup(NULL);
	if (null_test == NULL)
		printf("NULLが帰ってきたよ〜\n");

    return (0);
}
