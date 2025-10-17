#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    // isasciiの戻り値は0か非0かなので、真偽値として比較する
    int success = (res1 != 0) == (res2 != 0);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG (ft_isascii: %d, isascii: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for isascii =========\n\n");

    // --- 境界値（ASCIIの範囲内） ---
    print_result("Boundary Lower (0)", ft_isascii(0), isascii(0));
    print_result("Boundary Upper (127)", ft_isascii(127), isascii(127));

    // --- 境界値（ASCIIの範囲外） ---
    print_result("Boundary Outside (-1 / EOF)", ft_isascii(-1), isascii(-1));
    print_result("Boundary Outside (128)", ft_isascii(128), isascii(128));

    // --- 正常系（表示可能文字） ---
    print_result("Lowercase 'a'", ft_isascii('a'), isascii('a'));
    print_result("Uppercase 'Z'", ft_isascii('Z'), isascii('Z'));
    print_result("Digit '9'", ft_isascii('9'), isascii('9'));
    print_result("Space ' '", ft_isascii(' '), isascii(' '));
    print_result("Symbol '$'", ft_isascii('$'), isascii('$'));

    // --- 正常系（制御文字） ---
    print_result("Control Char '\\n'", ft_isascii('\n'), isascii('\n'));
    
    return (0);
}
