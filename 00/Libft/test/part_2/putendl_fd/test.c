#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void)
{
    int     fd;
    char    *buffer;
    ssize_t read_bytes;

    printf("========= Test Cases for putendl_fd =========\n\n");

    // --- テストケース1: 標準出力(fd=1)への書き込み ---
    printf("--- Test Case 1: Write to STDOUT (fd=1) ---\n");
    printf("Printing \"Hello STDOUT\" with a newline ->\n");
    ft_putendl_fd("Hello STDOUT", 1);
    printf("(The line above should have a newline)\n\n");

    // --- テストケース2: ファイルへの書き込みと読み出し ---
    printf("--- Test Case 2: Write to a file ---\n");
    const char *test_str = "This is a test for ft_putendl_fd.";
    const char *expected_str = "This is a test for ft_putendl_fd.\n"; // 期待される結果（改行付き）
    const char *filename = "test_putendl.txt";

    // 1. ファイルを開いて書き込む
    fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0)
    {
        perror("Failed to open file for writing");
        return (1);
    }
    printf("Writing \"%s\" to %s...\n", test_str, filename);
    ft_putendl_fd((char *)test_str, fd);
    close(fd);

    // 2. ファイルを開き直して読み出す
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Failed to open file for reading");
        return (1);
    }
    
    // 3. ファイルから読み込むためのバッファを確保
    buffer = (char *)malloc(sizeof(char) * (strlen(expected_str) + 1));
    if (!buffer)
    {
        close(fd);
        return (1);
    }
    read_bytes = read(fd, buffer, strlen(expected_str));
    buffer[read_bytes] = '\0'; // ヌル終端
    close(fd);

    // 4. 書き込んだ文字列と読み出した文字列が一致するか確認
    printf("Expected string:      \"%s\\n\"\n", test_str);
    printf("Read back string:     \"%s\"\n", buffer);
    if (strcmp(buffer, expected_str) == 0)
        printf("✅ OK: Strings match (newline included).\n");
    else
        printf("❌ NG: Strings do not match.\n");
    
    free(buffer);

	// 5. NULLポインタを渡した場合
    printf("\n\n========= Test Cases for NULL pointer =========\n\n");
	fd = open(filename, O_WRONLY);
	ft_putendl_fd(NULL, fd);
	printf("何も処理されず、関数が終了する。\n\n");

        
    return (0);
}
