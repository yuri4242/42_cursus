#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	if (len_dst >= size)
		return (size + len_src);
	if (len_src < size - len_dst - 1)
	{
		ft_memcpy(dst + len_dst, src, len_src);
		dst[len_dst + len_src] = '\0';
	}
	else if (size != 0)
	{
		ft_memcpy(dst + len_dst, src, size - len_dst - 1);
		dst[size - 1] = '\0';
	}
	return (len_dst + len_src);
}
