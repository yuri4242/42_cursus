#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*ptr;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len_s + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, len_s + 1);
	return (ptr);
}
