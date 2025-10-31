#include <stdio.h>
#include <fcntl.h>
#include "get_next_line.h"

void create_test_file(const char *filename, const char *content)
{
	int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		write(fd, content, gnl_strlen(content));
		close(fd);
	}
}

void print_header(const char *test_name)
{
	printf("\n--- %s (BUFFER_SIZE: %d) ---\n", test_name, BUFFER_SIZE);
}

int main(void)
{
	int		fd;
	char	*line;
	int		line_num;

	create_test_file("test_standard.txt", "line1\nline2\nline3\n");
	create_test_file("test_no_newline.txt", "abcdef");
	create_test_file("test_empty.txt", "");
	create_test_file("test_just_newline.txt", "\n");
	create_test_file("test_multiple_newlines.txt", "\n\n\nhello\n\n");
	create_test_file("test_long_line.txt", "01234567890123456789012345678901234567890123456789\n");

	// === ケース1: 正常系 (標準的なファイル) ===
	print_header("Standard File Test");
	fd = open("test_standard.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);

	// === ケース2: エッジケース (最後に改行がないファイル) ===
	print_header("No Newline at End Test");
	fd = open("test_no_newline.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);

	// === ケース3: エッジケース (空のファイル) ===
	print_header("Empty File Test");
	fd = open("test_empty.txt", O_RDONLY);
	line = get_next_line(fd);
	printf("Result: %s (NULL is correct)\n", line);
	free(line);
	close(fd);

	// === ケース4: エッジケース (改行だけのファイル) ===
	print_header("Just Newline Test");
	fd = open("test_just_newline.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s (empty line)\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);

	// === ケース5: 正常系 (複数・連続した改行) ===
	print_header("Multiple Newlines Test");
	fd = open("test_multiple_newlines.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);
	
	// === ケース6: 正常系 (BUFFER_SIZEより長い行) ===
	print_header("Long Line Test");
	fd = open("test_long_line.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);

	// === ケース7: 異常系 (無効な引数) ===
	print_header("Invalid FD Test");
	line = get_next_line(-1);
	printf("Result for fd = -1: %s (NULL is correct)\n", line);
	free(line);

	// === ケース8: 正常系 (標準入力) ===
	print_header("Standard Input Test");
	printf("Please type something and press Enter. (Ctrl+D to exit)\n");
	line_num = 1;
	while ((line = get_next_line(0)) != NULL)
	{
		printf("You typed [%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");

	return (0);
}
