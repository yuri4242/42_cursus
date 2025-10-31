#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	total;
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (malloc(1));
	total = nmemb * size;
	if (nmemb != 0 && total / nmemb != size)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);
	ft_memset(ptr, 0, total);
	return (ptr);
}
