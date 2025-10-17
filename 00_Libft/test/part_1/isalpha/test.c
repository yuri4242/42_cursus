#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    // isalphaの戻り値は0か非0かなので、真偽値として比較する
    int success = (res1 != 0) == (res2 != 0);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG (ft_isalpha: %d, isalpha: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for isalpha =========\n\n");

    // --- 正常系（アルファベット） ---
    print_result("Lowercase 'a'", ft_isalpha('a'), isalpha('a'));
    print_result("Lowercase 'z'", ft_isalpha('z'), isalpha('z'));
    print_result("Uppercase 'A'", ft_isalpha('A'), isalpha('A'));
    print_result("Uppercase 'Z'", ft_isalpha('Z'), isalpha('Z'));

    // --- 正常系（アルファベット以外） ---
    print_result("Digit '0'", ft_isalpha('0'), isalpha('0'));
    print_result("Digit '9'", ft_isalpha('9'), isalpha('9'));
    print_result("Space ' '", ft_isalpha(' '), isalpha(' '));
    print_result("Symbol '@'", ft_isalpha('@'), isalpha('@'));

    // --- 境界値 ---
    print_result("Boundary before 'a'", ft_isalpha('a' - 1), isalpha('a' - 1));
    print_result("Boundary after 'z'", ft_isalpha('z' + 1), isalpha('z' + 1));
    print_result("Boundary before 'A'", ft_isalpha('A' - 1), isalpha('A' - 1));
    print_result("Boundary after 'Z'", ft_isalpha('Z' + 1), isalpha('Z' + 1));

    // --- エッジケース ---
    print_result("NULL character '\\0'", ft_isalpha('\0'), isalpha('\0'));
    print_result("EOF (-1)", ft_isalpha(-1), isalpha(-1));
    print_result("Extended ASCII (127)", ft_isalpha(127), isalpha(127));
    print_result("Extended ASCII (200)", ft_isalpha(200), isalpha(200));

    return (0);
}
