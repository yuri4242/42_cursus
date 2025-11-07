#include "header/ft_printf.h" // あなたの ft_printf.h
#include <unistd.h>    // write, close, STDOUT_FILENO, STDERR_FILENO
#include <limits.h>    // INT_MIN, INT_MAX, UINT_MAX

/*
 * テスト結果を STDERR (fd: 2) に出力するためのヘルパー関数
 * (STDOUT は閉じてしまうため、printf や ft_printf 自身は使えない)
 */
static void test_putstr_fd(const char *s, int fd)
{
	int len = 0;
	while (s[len])
		len++;
	write(fd, s, len);
}

static void test_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		test_putstr_fd("-2147483648", fd);
		return;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	if (n >= 10)
		test_putnbr_fd(n / 10, fd);
	char c = (n % 10) + '0';
	write(fd, &c, 1);
}

/*
 * 戻り値(ret)が -1 であることを確認するヘルパー関数
 */
static void check_ret(const char *specifier, int ret)
{
	test_putstr_fd("Checking '", STDERR_FILENO);
	test_putstr_fd(specifier, STDERR_FILENO);
	test_putstr_fd("': ", STDERR_FILENO);
	if (ret == -1)
	{
		// Green color for PASSED
		test_putstr_fd("\033[32mPASSED\033[0m\n", STDERR_FILENO);
	}
	else
	{
		// Red color for FAILED
		test_putstr_fd("\033[31mFAILED\033[0m. Expected -1, Got: ", STDERR_FILENO);
		test_putnbr_fd(ret, STDERR_FILENO);
		write(STDERR_FILENO, "\n", 1);
	}
}

int main(void)
{
	int ret;
	void *p_null = NULL;
	void *p_valid = (void *)0x12345678;

	test_putstr_fd("--- 📢 Starting write() failure test ---\n", STDERR_FILENO);
	
	// 1. STDOUT_FILENO を閉じる
	if (close(STDOUT_FILENO) == -1)
	{
		test_putstr_fd("Error: Failed to close STDOUT_FILENO.\n", STDERR_FILENO);
		return 1;
	}
	test_putstr_fd("STDOUT_FILENO closed. Running tests...\n\n", STDERR_FILENO);

	// --- 2. 各識別子のテストを実行 ---

	// %c
	ret = ft_printf("%c", 'a');
	check_ret("%c", ret);

	// %s
	ret = ft_printf("%s", "Hello world");
	check_ret("%s", ret);
	ret = ft_printf("%s", (char *)NULL);
	check_ret("%s (NULL)", ret);

	// %p
	ret = ft_printf("%p", p_valid);
	check_ret("%p (valid)", ret);
	ret = ft_printf("%p", p_null);
	check_ret("%p (NULL)", ret);
	
	// %d / %i
	ret = ft_printf("%d", 123);
	check_ret("%d", ret);
	ret = ft_printf("%i", -456);
	check_ret("%i", ret);
	ret = ft_printf("%d", INT_MAX);
	check_ret("%d (INT_MAX)", ret);
	ret = ft_printf("%d", INT_MIN);
	check_ret("%d (INT_MIN)", ret);

	// %u
	ret = ft_printf("%u", 987);
	check_ret("%u", ret);
	ret = ft_printf("%u", 0);
	check_ret("%u (0)", ret);
	ret = ft_printf("%u", UINT_MAX);
	check_ret("%u (UINT_MAX)", ret);

	// %x
	ret = ft_printf("%x", 0xABCD);
	check_ret("%x", ret);

	// %X
	ret = ft_printf("%X", 0xDEADBEEF);
	check_ret("%X", ret);

	// %%
	ret = ft_printf("%%");
	check_ret("%%", ret);

	// 複合テスト
	ret = ft_printf("Mix: %c %s %p %d %u %% %x", 'Z', "test", p_valid, -100, 200, 0xFF);
	check_ret("Complex Mix", ret);

	// フラグ付き
	ret = ft_printf("Flag test: [%-10s] [%05d] [%.3p]", "flag", 12, p_valid);
	check_ret("Flags (width/padding)", ret);


	test_putstr_fd("\n--- Test complete ---\n", STDERR_FILENO);
	return (0);
}
