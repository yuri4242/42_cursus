#include "libft.h"
#include <stdio.h>
#include <ctype.h> 

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    // isprintの戻り値は0か非0かなので、真偽値として比較する
    int success = (res1 != 0) == (res2 != 0);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG (ft_isprint: %d, isprint: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for isprint =========\n\n");

    // --- 正常系（表示可能文字） ---
    print_result("Lowercase 'a'", ft_isprint('a'), isprint('a'));
    print_result("Digit '9'", ft_isprint('9'), isprint('9'));
    print_result("Symbol '$'", ft_isprint('$'), isprint('$'));

    // --- 境界値（表示可能文字の範囲） ---
    print_result("Boundary Lower (space, 32)", ft_isprint(' '), isprint(' '));
    print_result("Boundary Upper (~, 126)", ft_isprint('~'), isprint('~'));

    // --- 境界値（表示可能文字の範囲外） ---
    print_result("Boundary Outside (31)", ft_isprint(31), isprint(31));
    print_result("Boundary Outside (DEL, 127)", ft_isprint(127), isprint(127));

    // --- 正常系（制御文字） ---
    print_result("Control Char '\\n'", ft_isprint('\n'), isprint('\n'));
    print_result("Control Char '\\t'", ft_isprint('\t'), isprint('\t'));
    print_result("NULL character '\\0'", ft_isprint('\0'), isprint('\0'));

    // --- エッジケース ---
    print_result("EOF (-1)", ft_isprint(-1), isprint(-1));
    
    return (0);
}
