#ifndef PARSE_H
# define PARSE_H

# include <stdarg.h>
# include "libft.h"

int		parse_specifier(va_list ap, char specifier, t_flags flags);
void	parse_flags(const char **fmt, t_flags *flags);
void	parse_width(const char **fmt, va_list ap, t_flags *flags);
void	parse_precision(const char **fmt, va_list ap, t_flags *flags);

#endif
