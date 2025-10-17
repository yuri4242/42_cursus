#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

// テストを実行し、ファイルに書き込んだ結果を期待値と比較するヘルパー関数
void run_test(const char *test_name, int n, const char *expected)
{
    int     fd;
    char    buffer[50];
    ssize_t read_bytes;
    int     success = 0;
    const char *filename = "test_putnbr.txt";

    printf("--- %s ---\n", test_name);
    printf("Input: %d\n", n);

    // 1. ファイルを開いてft_putnbr_fdで書き込む
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("Open for write failed");
        return;
    }
    ft_putnbr_fd(n, fd);
    close(fd);

    // 2. ファイルを開き直して読み出す
    fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Open for read failed");
        return;
    }
    read_bytes = read(fd, buffer, 49);
    buffer[read_bytes] = '\0'; // ヌル終端
    close(fd);

    // 3. 読み出した内容と期待値が一致するか確認
    if (strcmp(buffer, expected) == 0)
        success = 1;
    
    printf("Expected: \"%s\"\n", expected);
    printf("Got     : \"%s\"\n", buffer);
    if (success)
        printf("✅ OK\n\n");
    else
        printf("❌ NG\n\n");
    
    unlink(filename); // テストファイルを削除
}

int main(void)
{
    printf("========= Test Cases for putnbr_fd =========\n\n");

    // --- テストケース1: 通常の正の数 ---
    run_test("Test 1: Normal Positive", 12345, "12345");

    // --- テストケース2: 通常の負の数 ---
    run_test("Test 2: Normal Negative", -6789, "-6789");

    // --- テストケース3: 0 ---
    run_test("Test 3: Zero", 0, "0");

    // --- テストケース4: intの最大値 ---
    run_test("Test 4: INT_MAX", INT_MAX, "2147483647");

    // --- テストケース5: intの最小値 (最重要) ---
    run_test("Test 5: INT_MIN", INT_MIN, "-2147483648");
    
    // --- テストケース6: 標準出力への書き込み ---
    printf("--- Test 6: Write to STDOUT ---\n");
    printf("Printing -42 to stdout -> ");
    ft_putnbr_fd(-42, 1);
    printf("\n\n");

    return (0);
}
