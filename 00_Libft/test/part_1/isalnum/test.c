#include "libft.h"
#include <stdio.h>
#include <ctype.h>

// 結果を分かりやすく表示するためのヘルパー関数
void print_result(const char *test_name, int res1, int res2)
{
    // isalnumの戻り値は0か非0かなので、真偽値として比較する
    int success = (res1 != 0) == (res2 != 0);

    printf("%-35s: ", test_name);
    if (success)
        printf("✅ OK\n");
    else
        printf("❌ NG (ft_isalnum: %d, isalnum: %d)\n", res1, res2);
}

int main(void)
{
    printf("========= Test Cases for isalnum =========\n\n");

    // --- 正常系（アルファベットまたは数字） ---
    print_result("Lowercase 'a'", ft_isalnum('a'), isalnum('a'));
    print_result("Uppercase 'Z'", ft_isalnum('Z'), isalnum('Z'));
    print_result("Digit '0'", ft_isalnum('0'), isalnum('0'));
    print_result("Digit '9'", ft_isalnum('9'), isalnum('9'));

    // --- 正常系（アルファベット・数字以外） ---
    print_result("Space ' '", ft_isalnum(' '), isalnum(' '));
    print_result("Symbol '$'", ft_isalnum('$'), isalnum('$'));
    print_result("Punctuation ','", ft_isalnum(','), isalnum(','));

    // --- 境界値 ---
    print_result("Boundary before 'a'", ft_isalnum('a' - 1), isalnum('a' - 1));
    print_result("Boundary after 'z'", ft_isalnum('z' + 1), isalnum('z' + 1));
    print_result("Boundary before 'A'", ft_isalnum('A' - 1), isalnum('A' - 1));
    print_result("Boundary after 'Z'", ft_isalnum('Z' + 1), isalnum('Z' + 1));
    print_result("Boundary before '0'", ft_isalnum('0' - 1), isalnum('0' - 1));
    print_result("Boundary after '9'", ft_isalnum('9' + 1), isalnum('9' + 1));

    // --- エッジケース ---
    print_result("NULL character '\\0'", ft_isalnum('\0'), isalnum('\0'));
    print_result("EOF (-1)", ft_isalnum(-1), isalnum(-1));
    
    return (0);
}
