#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

// テストファイルを自動生成するヘルパー関数
void create_test_file(const char *filename, const char *content)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        write(fd, content, ft_strlen(content)); // ft_strlenは自作のものを使用
        close(fd);
    }
}

// テスト結果を表示するヘッダー
void print_header(const char *test_name)
{
    printf("\n--- %s (BUFFER_SIZE: %d) ---\n", test_name, BUFFER_SIZE);
}

int main(void)
{
    int     fd;
    char    *line;
    int     ret;
    int     line_num;

    // --- テスト用のファイルを作成 ---
    create_test_file("test_standard.txt", "line1\nline2\nline3\n");
    create_test_file("test_no_newline.txt", "abcdef");
    create_test_file("test_empty.txt", "");
    create_test_file("test_just_newline.txt", "\n");
    create_test_file("test_multiple_newlines.txt", "\n\n\nhello\n\n");
    create_test_file("test_long_line.txt", "01234567890123456789012345678901234567890123456789\n");

    // === ケース1: 標準的なファイル ===
    print_header("Standard File Test");
    fd = open("test_standard.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);

    // === ケース2: 最後に改行がないファイル ===
    print_header("No Newline at End Test");
    fd = open("test_no_newline.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);

    // === ケース3: 空のファイル ===
    print_header("Empty File Test");
    fd = open("test_empty.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);

    // === ケース4: 改行だけのファイル ===
    print_header("Just Newline Test");
    fd = open("test_just_newline.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s (empty line)\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);

    // === ケース5: 複数・連続した改行 ===
    print_header("Multiple Newlines Test");
    fd = open("test_multiple_newlines.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);
    
    // === ケース6: BUFFER_SIZEより長い行 ===
    print_header("Long Line Test");
    fd = open("test_long_line.txt", O_RDONLY);
    line_num = 1;
    while ((ret = get_next_line(fd, &line)) > 0)
    {
        printf("[%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);
    close(fd);

    // === ケース7: 無効なファイルディスクリプタ ===
    print_header("Invalid FD Test");
    ret = get_next_line(-1, &line);
    printf("Return for fd = -1: %d (-1 is success)\n", ret);

    // === ケース8: 標準入力 (fd = 0) ===
    // このテストを実行すると、プログラムはキーボードからの入力を待ちます。
    // Ctrl+D を押すと終了します。
    print_header("Standard Input Test");
    printf("Please type something and press Enter. (Ctrl+D to exit)\n");
    line_num = 1;
    while ((ret = get_next_line(0, &line)) > 0)
    {
        printf("You typed [%d]: %s\n", line_num++, line);
        free(line);
    }
    printf("Final return value: %d (0 is success)\n", ret);

    return (0);
}
