#include <unistd.h> // write, open, close
#include <fcntl.h>  // O_WRONLY, O_CREATなど
#include <stdio.h>  // printf

int main(void)
{
	int fd;

	printf("--- 正常系テスト ---\n");
	// 1. 標準出力
	printf("1. 標準出力(stdout)への書き込み: \n\n");
	ft_putchar_fd('A', 1);
	ft_putchar_fd('\n', 1);

	// 2. ファイルへの書き込み
	printf("2. test_file.txt への書き込み...\n");
	fd = open("test_file.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('F', fd);
		ft_putchar_fd('\n', fd);
		close(fd);
		printf("   -> 完了。`cat test_file.txt` で確認してください。\n");
	}

	printf("\n--- 異常系・エッジケーステスト ---\n");
	printf("3. 無効なfd(-1)への書き込み (クラッシュしなければOK)\n");
	ft_putchar_fd('X', -1);

	printf("4. 閉じたfdへの書き込み (クラッシュしなければOK)\n");
	fd = open("tmp.txt", O_WRONLY | O_CREAT, 0644);
	close(fd);
	ft_putchar_fd('Z', fd);

	printf("5. NULL文字(\\0)の書き込み\n");
	fd = open("null_char_test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
	{
		ft_putchar_fd('N', fd);
		ft_putchar_fd('\0', fd); // NULL文字を書き込む
		ft_putchar_fd('L', fd);
		close(fd);
		printf("   -> 完了。`cat -v null_char_test.txt` で N^@L と見えれば成功。\n\n");
	}

	printf("全てのテストがクラッシュせずに終了しました\n");
	return (0);
}
