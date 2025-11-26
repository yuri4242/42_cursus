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
        printf("❌ NG (ft_tolower: %d, tolower: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for tolower =========\n\n");

    // --- 正常系（大文字→小文字） ---
    print_result("Uppercase 'A'", ft_tolower('A'), tolower('A'));
    print_result("Uppercase 'Z'", ft_tolower('Z'), tolower('Z'));
    
    // --- 正常系（変化しない文字） ---
    print_result("Lowercase 'a'", ft_tolower('a'), tolower('a'));
    print_result("Lowercase 'z'", ft_tolower('z'), tolower('z'));
    print_result("Digit '5'", ft_tolower('5'), tolower('5'));
    print_result("Symbol '$'", ft_tolower('$'), tolower('$'));
    print_result("Space ' '", ft_tolower(' '), tolower(' '));

    // --- 境界値 ---
    print_result("Boundary before 'A'", ft_tolower('A' - 1), tolower('A' - 1));
    print_result("Boundary after 'Z'", ft_tolower('Z' + 1), tolower('Z' + 1));

    // --- エッジケース ---
    print_result("NULL character '\\0'", ft_tolower('\0'), tolower('\0'));
    print_result("EOF (-1)", ft_tolower(-1), tolower(-1));
    print_result("Extended ASCII (128)", ft_tolower(128), tolower(128));
    
    return (0);
}
