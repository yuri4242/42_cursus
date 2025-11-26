#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    // isdigitの戻り値は0か非0かなので、真偽値として比較する
    int success = (res1 != 0) == (res2 != 0);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG (ft_isdigit: %d, isdigit: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for isdigit =========\n\n");

    // --- 正常系（数字） ---
    print_result("Digit '0'", ft_isdigit('0'), isdigit('0'));
    print_result("Digit '5'", ft_isdigit('5'), isdigit('5'));
    print_result("Digit '9'", ft_isdigit('9'), isdigit('9'));

    // --- 正常系（数字以外） ---
    print_result("Lowercase 'a'", ft_isdigit('a'), isdigit('a'));
    print_result("Uppercase 'Z'", ft_isdigit('Z'), isdigit('Z'));
    print_result("Space ' '", ft_isdigit(' '), isdigit(' '));
    print_result("Symbol '&'", ft_isdigit('&'), isdigit('&'));

    // --- 境界値 ---
    print_result("Boundary before '0'", ft_isdigit('0' - 1), isdigit('0' - 1));
    print_result("Boundary after '9'", ft_isdigit('9' + 1), isdigit('9' + 1));

    // --- エッジケース ---
    print_result("NULL character '\\0'", ft_isdigit('\0'), isdigit('\0'));
    print_result("EOF (-1)", ft_isdigit(-1), isdigit(-1));
    print_result("Extended ASCII (127)", ft_isdigit(127), isdigit(127));
    print_result("Extended ASCII (255)", ft_isdigit(255), isdigit(255));

    return (0);
}
