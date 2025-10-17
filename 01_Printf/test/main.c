#include <stdio.h>
#include <limits.h>
#include "ft_printf.h" // ご自身のft_printf.hをインクルードしてください

// テスト結果を比較し、分かりやすく表示するためのカウンター
static int test_count = 0;
static int passed_count = 0;

// 比較結果を出力するヘルパー関数
void print_result(int ft_ret, int og_ret)
{
    test_count++;
    printf("ft_printf returned: %d\n", ft_ret);
    printf("   printf returned: %d\n", og_ret);
    if (ft_ret == og_ret)
    {
        printf("✅ SUCCESS: Return values match.\n");
        passed_count++;
    }
    else
    {
        printf("❌ FAILURE: Return values DO NOT match.\n");
    }
    printf("----------------------------------------\n\n");
}

int main(void)
{
    // テスト用の変数を宣言
    int ft_ret;
    int og_ret;
    char *s_null = NULL;
    int test_var = 42;

    printf("========= ft_printf Test Suite =========\n\n");

    // ==================================================
    // 1. 文字 (%c) テスト
    // ==================================================
    printf("--- Category: %%c (Character) ---\n");
    // Test C-01: 基本的な文字
    printf("[C-01] Testing: \"[%%c]\", 'A'\n");
    ft_ret = ft_printf("ft_printf: [%c]\n", 'A');
    og_ret = printf("   printf: [%c]\n", 'A');
    print_result(ft_ret, og_ret);

    // Test C-02: 幅の指定 (右揃え)
    printf("[C-02] Testing: \"[%%5c]\", 'B'\n");
    ft_ret = ft_printf("ft_printf: [%5c]\n", 'B');
    og_ret = printf("   printf: [%5c]\n", 'B');
    print_result(ft_ret, og_ret);

    // Test C-03: 幅と左揃え
    printf("[C-03] Testing: \"[%%-5c]\", 'C'\n");
    ft_ret = ft_printf("ft_printf: [%-5c]\n", 'C');
    og_ret = printf("   printf: [%-5c]\n", 'C');
    print_result(ft_ret, og_ret);
    
    // Test C-04: ヌル文字の出力
    printf("[C-04] Testing: \"[%%c]\", '\\0'\n");
    ft_ret = ft_printf("ft_printf: [%c]\n", '\0');
    og_ret = printf("   printf: [%c]\n", '\0');
    print_result(ft_ret, og_ret);

    // ==================================================
    // 2. 文字列 (%s) テスト
    // ==================================================
    printf("--- Category: %%s (String) ---\n");
    // Test S-01: 基本的な文字列
    printf("[S-01] Testing: \"[%%s]\", \"Hello\"\n");
    ft_ret = ft_printf("ft_printf: [%s]\n", "Hello");
    og_ret = printf("   printf: [%s]\n", "Hello");
    print_result(ft_ret, og_ret);

    // Test S-02: NULLポインタ
    printf("[S-02] Testing: \"[%%s]\", NULL\n");
    ft_ret = ft_printf("ft_printf: [%s]\n", s_null);
    og_ret = printf("   printf: [%s]\n", s_null);
    print_result(ft_ret, og_ret);

    // Test S-03: 空文字列
    printf("[S-03] Testing: \"[%%s]\", \"\"\n");
    ft_ret = ft_printf("ft_printf: [%s]\n", "");
    og_ret = printf("   printf: [%s]\n", "");
    print_result(ft_ret, og_ret);

    // Test S-04 to S-11: 幅、精度、左揃えの組み合わせ
    printf("[S-04] Testing: \"[%%10s]\", \"test\"\n");
    ft_ret = ft_printf("ft_printf: [%10s]\n", "test");
    og_ret = printf("   printf: [%10s]\n", "test");
    print_result(ft_ret, og_ret);

    printf("[S-05] Testing: \"[%%-10s]\", \"test\"\n");
    ft_ret = ft_printf("ft_printf: [%-10s]\n", "test");
    og_ret = printf("   printf: [%-10s]\n", "test");
    print_result(ft_ret, og_ret);

    printf("[S-06] Testing: \"[%%.3s]\", \"abcdef\"\n");
    ft_ret = ft_printf("ft_printf: [%.3s]\n", "abcdef");
    og_ret = printf("   printf: [%.3s]\n", "abcdef");
    print_result(ft_ret, og_ret);

    printf("[S-07] Testing: \"[%%.10s]\", \"abcdef\"\n");
    ft_ret = ft_printf("ft_printf: [%.10s]\n", "abcdef");
    og_ret = printf("   printf: [%.10s]\n", "abcdef");
    print_result(ft_ret, og_ret);
    
    printf("[S-08] Testing: \"[%%.0s]\", \"abcdef\"\n");
    ft_ret = ft_printf("ft_printf: [%.0s]\n", "abcdef");
    og_ret = printf("   printf: [%.0s]\n", "abcdef");
    print_result(ft_ret, og_ret);

    printf("[S-09] Testing: \"[%%10.3s]\", \"abcdef\"\n");
    ft_ret = ft_printf("ft_printf: [%10.3s]\n", "abcdef");
    og_ret = printf("   printf: [%10.3s]\n", "abcdef");
    print_result(ft_ret, og_ret);

    printf("[S-10] Testing: \"[%%-10.3s]\", \"abcdef\"\n");
    ft_ret = ft_printf("ft_printf: [%-10.3s]\n", "abcdef");
    og_ret = printf("   printf: [%-10.3s]\n", "abcdef");
    print_result(ft_ret, og_ret);
    
    printf("[S-11] Testing: \"[%%.2s]\", NULL\n");
    ft_ret = ft_printf("ft_printf: [%.2s]\n", s_null);
    og_ret = printf("   printf: [%.2s]\n", s_null);
    print_result(ft_ret, og_ret);


    // ==================================================
    // 3. ポインタ (%p) テスト
    // ==================================================
    printf("--- Category: %%p (Pointer) ---\n");
    // Test P-01: 基本的なポインタ
    printf("[P-01] Testing: \"[%%p]\", &test_var\n");
    ft_ret = ft_printf("ft_printf: [%p]\n", &test_var);
    og_ret = printf("   printf: [%p]\n", &test_var);
    print_result(ft_ret, og_ret);

    // Test P-02: NULLポインタ
    printf("[P-02] Testing: \"[%%p]\", NULL\n");
    ft_ret = ft_printf("ft_printf: [%p]\n", NULL);
    og_ret = printf("   printf: [%p]\n", NULL);
    print_result(ft_ret, og_ret);

    // Test P-03 to P-05: 幅、左揃えの組み合わせ
    printf("[P-03] Testing: \"[%%20p]\", &test_var\n");
    ft_ret = ft_printf("ft_printf: [%20p]\n", &test_var);
    og_ret = printf("   printf: [%20p]\n", &test_var);
    print_result(ft_ret, og_ret);
    
    printf("[P-04] Testing: \"[%%-20p]\", &test_var\n");
    ft_ret = ft_printf("ft_printf: [%-20p]\n", &test_var);
    og_ret = printf("   printf: [%-20p]\n", &test_var);
    print_result(ft_ret, og_ret);
    
    printf("[P-05] Testing: \"[%%10p]\", NULL\n");
    ft_ret = ft_printf("ft_printf: [%10p]\n", NULL);
    og_ret = printf("   printf: [%10p]\n", NULL);
    print_result(ft_ret, og_ret);

    // ==================================================
    // 4. 整数 (%d, %i) テスト
    // ==================================================
    printf("--- Category: %%d, %%i (Integer) ---\n");
    // Test D-01 to D-12: 境界値、フラグ、幅、精度の組み合わせ
    printf("[D-01] Testing: \"[%%d]\", 123\n");
    ft_ret = ft_printf("ft_printf: [%d]\n", 123);
    og_ret = printf("   printf: [%d]\n", 123);
    print_result(ft_ret, og_ret);
    
    printf("[D-02] Testing: \"[%%d]\", -123\n");
    ft_ret = ft_printf("ft_printf: [%d]\n", -123);
    og_ret = printf("   printf: [%d]\n", -123);
    print_result(ft_ret, og_ret);
    
    printf("[D-03] Testing: \"[%%d]\", 0\n");
    ft_ret = ft_printf("ft_printf: [%d]\n", 0);
    og_ret = printf("   printf: [%d]\n", 0);
    print_result(ft_ret, og_ret);
    
    printf("[D-04] Testing: \"[%%d]\", INT_MAX\n");
    ft_ret = ft_printf("ft_printf: [%d]\n", INT_MAX);
    og_ret = printf("   printf: [%d]\n", INT_MAX);
    print_result(ft_ret, og_ret);
    
    printf("[D-05] Testing: \"[%%d]\", INT_MIN\n");
    ft_ret = ft_printf("ft_printf: [%d]\n", INT_MIN);
    og_ret = printf("   printf: [%d]\n", INT_MIN);
    print_result(ft_ret, og_ret);
    
    printf("[D-06] Testing: \"[%%08d]\", 42\n");
    ft_ret = ft_printf("ft_printf: [%08d]\n", 42);
    og_ret = printf("   printf: [%08d]\n", 42);
    print_result(ft_ret, og_ret);
    
    printf("[D-07] Testing: \"[%%08d]\", -42\n");
    ft_ret = ft_printf("ft_printf: [%08d]\n", -42);
    og_ret = printf("   printf: [%08d]\n", -42);
    print_result(ft_ret, og_ret);
    
    printf("[D-08] Testing: \"[%%.5d]\", 42\n");
    ft_ret = ft_printf("ft_printf: [%.5d]\n", 42);
    og_ret = printf("   printf: [%.5d]\n", 42);
    print_result(ft_ret, og_ret);
    
    printf("[D-09] Testing: \"[%%.5d]\", -42\n");
    ft_ret = ft_printf("ft_printf: [%.5d]\n", -42);
    og_ret = printf("   printf: [%.5d]\n", -42);
    print_result(ft_ret, og_ret);
    
    printf("[D-10] Testing: \"[%%.0d]\", 0\n");
    ft_ret = ft_printf("ft_printf: [%.0d]\n", 0);
    og_ret = printf("   printf: [%.0d]\n", 0);
    print_result(ft_ret, og_ret);
    
    printf("[D-11] Testing: \"[%%010.5d]\", 42\n");
    ft_ret = ft_printf("ft_printf: [%010.5d]\n", 42);
    og_ret = printf("   printf: [%010.5d]\n", 42);
    print_result(ft_ret, og_ret);
    
    printf("[D-12] Testing: \"[%%-10.5d]\", 42\n");
    ft_ret = ft_printf("ft_printf: [%-10.5d]\n", 42);
    og_ret = printf("   printf: [%-10.5d]\n", 42);
    print_result(ft_ret, og_ret);
    
    // ==================================================
    // 5. 符号なし整数 (%u) テスト
    // ==================================================
    printf("--- Category: %%u (Unsigned Integer) ---\n");
    // Test U-01 to U-04
    printf("[U-01] Testing: \"[%%u]\", 123\n");
    ft_ret = ft_printf("ft_printf: [%u]\n", 123U);
    og_ret = printf("   printf: [%u]\n", 123U);
    print_result(ft_ret, og_ret);
    
    printf("[U-02] Testing: \"[%%u]\", -1\n");
    ft_ret = ft_printf("ft_printf: [%u]\n", -1);
    og_ret = printf("   printf: [%u]\n", -1);
    print_result(ft_ret, og_ret);
    
    printf("[U-03] Testing: \"[%%u]\", UINT_MAX\n");
    ft_ret = ft_printf("ft_printf: [%u]\n", UINT_MAX);
    og_ret = printf("   printf: [%u]\n", UINT_MAX);
    print_result(ft_ret, og_ret);
    
    printf("[U-04] Testing: \"[%%010.5u]\", 123\n");
    ft_ret = ft_printf("ft_printf: [%010.5u]\n", 123U);
    og_ret = printf("   printf: [%010.5u]\n", 123U);
    print_result(ft_ret, og_ret);

    // ==================================================
    // 6. 16進数 (%x, %X) テスト
    // ==================================================
    printf("--- Category: %%x, %%X (Hexadecimal) ---\n");
    // Test X-01 to X-05
    printf("[X-01] Testing: \"[%%x]\", 255\n");
    ft_ret = ft_printf("ft_printf: [%x]\n", 255);
    og_ret = printf("   printf: [%x]\n", 255);
    print_result(ft_ret, og_ret);
    
    printf("[X-02] Testing: \"[%%x]\", -1\n");
    ft_ret = ft_printf("ft_printf: [%x]\n", -1);
    og_ret = printf("   printf: [%x]\n", -1);
    print_result(ft_ret, og_ret);
    
    printf("[X-03] Testing: \"[%%010.5x]\", 255\n");
    ft_ret = ft_printf("ft_printf: [%010.5x]\n", 255);
    og_ret = printf("   printf: [%010.5x]\n", 255);
    print_result(ft_ret, og_ret);
    
    printf("[X-04] Testing: \"[%%X]\", 48879\n");
    ft_ret = ft_printf("ft_printf: [%X]\n", 48879);
    og_ret = printf("   printf: [%X]\n", 48879);
    print_result(ft_ret, og_ret);

    printf("[X-05] Testing: \"[%%10.6X]\", 48879\n");
    ft_ret = ft_printf("ft_printf: [%10.6X]\n", 48879);
    og_ret = printf("   printf: [%10.6X]\n", 48879);
    print_result(ft_ret, og_ret);

    // ==================================================
    // 7. パーセント (%%) テスト
    // ==================================================
    printf("--- Category: %%%% (Percent) ---\n");
    // Test PCT-01 to PCT-03
    printf("[PCT-01] Testing: \"[%%%%]\"\n");
    ft_ret = ft_printf("ft_printf: [%%]\n");
    og_ret = printf("   printf: [%%]\n");
    print_result(ft_ret, og_ret);

    printf("[PCT-02] Testing: \"[%%05%%]\"\n");
    ft_ret = ft_printf("ft_printf: [%05%]\n");
    og_ret = printf("   printf: [%05%]\n");
    print_result(ft_ret, og_ret);
    
    printf("[PCT-03] Testing: \"[%%-5%%]\"\n");
    ft_ret = ft_printf("ft_printf: [%-5%]\n");
    og_ret = printf("   printf: [%-5%]\n");
    print_result(ft_ret, og_ret);
    
    // ==================================================
    // 8. 複数指定テスト
    // ==================================================
    printf("--- Category: Mixed ---\n");
    // Test MIX-01, MIX-02
    printf("[MIX-01] Testing: \"[%%s: %%d]\", \"num\", 42\n");
    ft_ret = ft_printf("ft_printf: [%s: %d]\n", "num", 42);
    og_ret = printf("   printf: [%s: %d]\n", "num", 42);
    print_result(ft_ret, og_ret);

    printf("[MIX-02] Testing: \"[%%-10.5s: %%08d]\", \"test\", -123\n");
    ft_ret = ft_printf("ft_printf: [%-10.5s: %08d]\n", "test", -123);
    og_ret = printf("   printf: [%-10.5s: %08d]\n", "test", -123);
    print_result(ft_ret, og_ret);

    // ==================================================
    // 9. 最終結果
    // ==================================================
    printf("\n========== Test Summary ==========\n");
    printf("Total Tests: %d\n", test_count);
    printf("Passed: %d\n", passed_count);
    printf("Failed: %d\n", test_count - passed_count);
    printf("==================================\n");

    return (0);
}
