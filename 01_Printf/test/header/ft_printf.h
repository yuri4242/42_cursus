#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	dot;
	int	precision;
}	t_flags;

# include "print.h"
# include "parse.h"
# include "util.h"

int	ft_printf(const char *fmt, ...);

#endif
