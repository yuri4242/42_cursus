#include <stdio.h>
#include <fcntl.h>
#include "../test/get_next_line.h"

// テスト結果を表示するヘッダー
void print_header(const char *test_name)
{
	printf("\n--- %s (BUFFER_SIZE: %d) ---\n", test_name, BUFFER_SIZE);
}

int main(void)
{
	int		fd;
	char	*line;
	int		line_num;


	// === ケース1: 正常系 (標準的なファイル) ===
	print_header("Very Very long one line File Test");
	fd = open("giant_ling.txt", O_RDONLY);
	line_num = 1;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("[%d]: %s\n", line_num++, line);
		free(line);
	}
	printf("-> Reached EOF (NULL was returned)\n");
	close(fd);

	return (0);
}
