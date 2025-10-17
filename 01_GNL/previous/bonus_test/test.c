#include <stdio.h>
#include <fcntl.h>
#include "get_next_line_bonus.h"

// テストファイルを自動生成するヘルパー関数
void create_test_file(const char *filename, const char *content)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd != -1)
    {
        write(fd, content, ft_strlen(content));
        close(fd);
    }
}

void print_header(const char *test_name)
{
    printf("\n--- %s (BUFFER_SIZE: %d) ---\n", test_name, BUFFER_SIZE);
}

int main(void)
{
    int     fd1, fd2, fd3;
    char    *line;

    create_test_file("bonus_test1.txt", "File 1: Line 1\nFile 1: Line 2\nFile 1: Line 3");
    create_test_file("bonus_test2.txt", "File 2: Line 1\nFile 2: Line 2");
    create_test_file("bonus_test3.txt", "File 3: Line 1\nFile 3: Line 2\nFile 3: Line 3\nFile 3: Line 4");

    print_header("Multiple File Descriptors Test");

    fd1 = open("bonus_test1.txt", O_RDONLY);
    fd2 = open("bonus_test2.txt", O_RDONLY);
    fd3 = open("bonus_test3.txt", O_RDONLY);

    if (fd1 == -1 || fd2 == -1 || fd3 == -1)
    {
        printf("Error: Could not open test files.\n");
        return (1);
    }
    printf("Opened fd1=%d, fd2=%d, fd3=%d\n\n", fd1, fd2, fd3);

    // --- 交互に読み出し ---
    printf("Reading line 1 from fd1...\n");
    get_next_line(fd1, &line); printf(" -> %s\n", line); free(line);
    printf("Reading line 1 from fd2...\n");
    get_next_line(fd2, &line); printf(" -> %s\n", line); free(line);
    printf("Reading line 1 from fd3...\n");
    get_next_line(fd3, &line); printf(" -> %s\n", line); free(line);
    printf("\n");
    printf("Reading line 2 from fd1...\n");
    get_next_line(fd1, &line); printf(" -> %s\n", line); free(line);
    printf("Reading line 2 from fd3...\n");
    get_next_line(fd3, &line); printf(" -> %s\n", line); free(line);
    printf("Reading line 2 from fd2...\n");
    get_next_line(fd2, &line); printf(" -> %s\n", line); free(line);

    printf("\n--- Reading until all files reach EOF ---\n\n");

    int ret1 = 1, ret2 = 1, ret3 = 1;
    while (ret1 > 0 || ret2 > 0 || ret3 > 0)
    {
        if (ret1 > 0)
        {
            ret1 = get_next_line(fd1, &line);
            if (ret1 > 0) { printf("Read from fd1: %s\n", line); free(line); }
        }
        if (ret2 > 0)
        {
            ret2 = get_next_line(fd2, &line);
            if (ret2 > 0) { printf("Read from fd2: %s\n", line); free(line); }
        }
        if (ret3 > 0)
        {
            ret3 = get_next_line(fd3, &line);
            if (ret3 > 0) { printf("Read from fd3: %s\n", line); free(line); }
        }
    }
    printf("\nAll files have reached EOF.\n");

    close(fd1);
    close(fd2);
    close(fd3);

    return (0);
}
