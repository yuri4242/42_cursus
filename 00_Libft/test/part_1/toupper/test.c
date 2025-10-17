#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    int success = (res1 == res2);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK (Value: %c, %d)\n", res1, res1);
    else
        printf("❌ NG (ft_toupper: %d, toupper: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for toupper =========\n\n");

    // --- 正常系（小文字→大文字） ---
    print_result("Lowercase 'a'", ft_toupper('a'), toupper('a'));
    print_result("Lowercase 'z'", ft_toupper('z'), toupper('z'));
    
    // --- 正常系（変化しない文字） ---
    print_result("Uppercase 'A'", ft_toupper('A'), toupper('A'));
    print_result("Uppercase 'Z'", ft_toupper('Z'), toupper('Z'));
    print_result("Digit '5'", ft_toupper('5'), toupper('5'));
    print_result("Symbol '$'", ft_toupper('$'), toupper('$'));
    print_result("Space ' '", ft_toupper(' '), toupper(' '));

    // --- 境界値 ---
    print_result("Boundary before 'a'", ft_toupper('a' - 1), toupper('a' - 1));
    print_result("Boundary after 'z'", ft_toupper('z' + 1), toupper('z' + 1));

    // --- エッジケース ---
    print_result("NULL character '\\0'", ft_toupper('\0'), toupper('\0'));
    print_result("EOF (-1)", ft_toupper(-1), toupper(-1));
    print_result("Extended ASCII (128)", ft_toupper(128), toupper(128));
    
    return (0);
}
