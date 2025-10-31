#include <stdio.h>
#include <fcntl.h>
#include <string.h> // strlen のために追加
#include <unistd.h> // write, close のために追加
#include <stdlib.h> // free のために追加
#include "get_next_line.h" // ヘッダーを bonus 無しに変更

// テストファイルを自動生成するヘルパー関数
void create_test_file(const char *filename, const char *content)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		// ft_strlen を strlen に変更
		write(fd, content, strlen(content));
		close(fd);
	}
}

void print_header(const char *test_name)
{
	printf("\n--- %s (BUFFER_SIZE: %d) ---\n", test_name, BUFFER_SIZE);
}

int main(void)
{
	int		fd1, fd2, fd3;
	char	*line;

	create_test_file("bonus_test1.txt", "File 1: Line 1\nFile 1: Line 2\nFile 1: Line 3");
	create_test_file("bonus_test2.txt", "File 2: Line 1\nFile 2: Line 2");
	create_test_file("bonus_test3.txt", "File 3: Line 1\nFile 3: Line 2\nFile 3: Line 3\nFile 3: Line 4");

	print_header("Multiple File Descriptors Test (Mandatory Signature)");

	fd1 = open("bonus_test1.txt", O_RDONLY);
	fd2 = open("bonus_test2.txt", O_RDONLY);
	fd3 = open("bonus_test3.txt", O_RDONLY);

	if (fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		printf("Error: Could not open test files.\n");
		return (1);
	}
	printf("Opened fd1=%d, fd2=%d, fd3=%d\n\n", fd1, fd2, fd3);

	// --- 交互に読み出し (戻り値を受け取るように変更) ---
	printf("Reading line 1 from fd1...\n");
	line = get_next_line(fd1); printf(" -> %s\n", line); free(line);
	printf("Reading line 1 from fd2...\n");
	line = get_next_line(fd2); printf(" -> %s\n", line); free(line);
	printf("Reading line 1 from fd3...\n");
	line = get_next_line(fd3); printf(" -> %s\n", line); free(line);
	printf("\n");
	printf("Reading line 2 from fd1...\n");
	line = get_next_line(fd1); printf(" -> %s\n", line); free(line);
	printf("Reading line 2 from fd3...\n");
	line = get_next_line(fd3); printf(" -> %s\n", line); free(line);
	printf("Reading line 2 from fd2...\n");
	line = get_next_line(fd2); printf(" -> %s\n", line); free(line);

	printf("\n--- Reading until all files reach EOF ---\n\n");

	// EOF判定のロジックを、戻り値がNULLかどうかで判定するように変更
	char *line1 = (char *)1; // NULLでないダミー値で初期化
	char *line2 = (char *)1; // NULLでないダミー値で初期化
	char *line3 = (char *)1; // NULLでないダミー値で初期化

	while (line1 != NULL || line2 != NULL || line3 != NULL)
	{
		if (line1 != NULL)
		{
			line1 = get_next_line(fd1);
			if (line1 != NULL) { printf("Read from fd1: %s\n", line1); free(line1); }
		}
		if (line2 != NULL)
		{
			line2 = get_next_line(fd2);
			if (line2 != NULL) { printf("Read from fd2: %s\n", line2); free(line2); }
		}
		if (line3 != NULL)
		{
			line3 = get_next_line(fd3);
			if (line3 != NULL) { printf("Read from fd3: %s\n", line3); free(line3); }
		}
	}
	printf("\nAll files have reached EOF.\n");

	close(fd1);
	close(fd2);
	close(fd3);

	return (0);
}
