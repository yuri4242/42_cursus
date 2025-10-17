#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// 1. インデックスを文字コードに足す関数
char add_index_func(unsigned int i, char c)
{
    return (c + i);
}

// 2. 小文字を大文字に変換する関数（インデックスは使わない）
char toupper_func(unsigned int i, char c)
{
    (void)i; // iを使わないので、コンパイラ警告を抑制
    if (c >= 'a' && c <= 'z')
        return (c - 32);
    return (c);
}


// テストを実行し、結果を分かりやすく表示するヘルパー関数
void run_test(const char *test_name, const char *s, char (*f)(unsigned int, char), const char *expected)
{
    char *result = ft_strmapi(s, f);
    int success = 0;

    printf("--- %s ---\n", test_name);
    
    if (result && expected && strcmp(result, expected) == 0)
    {
        success = 1;
        printf("Result: \"%s\" (as expected)\n", result);
    }
    else if (result == NULL && expected == NULL)
    {
        success = 1;
        printf("Result: NULL (as expected)\n");
    }
    else
    {
        printf("Result: \"%s\", Expected: \"%s\"\n", result, expected);
    }

    if (success)
        printf("✅ OK\n\n");
    else
        printf("❌ NG\n\n");

    free(result); // ft_strmapiが確保したメモリを解放
}

int main(void)
{
    printf("========= Test Cases for strmapi =========\n\n");

    // --- テストケース1: 各文字を大文字に変換 ---
    run_test("Test 1: To Uppercase", "hello", &toupper_func, "HELLO");

    // --- テストケース2: 各文字にインデックスを足す ---
    // 'h'(104)+0, 'e'(101)+1, 'l'(108)+2, 'l'(108)+3, 'o'(111)+4
    // -> 104, 102, 110, 111, 115 -> "hfnos"
    run_test("Test 2: Add Index", "hello", &add_index_func, "hfnos");

    // --- テストケース3: 空文字列 ---
    run_test("Test 3: Empty String", "", &toupper_func, "");

    // --- テストケース4: sがNULL ---
    run_test("Test 4: s is NULL", NULL, &toupper_func, NULL);
    
    // --- テストケース5: fがNULL ---
    run_test("Test 5: f is NULL", "hello", NULL, NULL);

    return (0);
}
