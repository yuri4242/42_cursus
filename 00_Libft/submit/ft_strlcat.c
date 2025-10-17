/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata  <yikebata@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:59:35 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/16 12:19:29 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_copy;
	size_t	len_dst;
	size_t	len_src;

	if (src == NULL)
	{
		if (dst == NULL)
			return (0);
		return (ft_strlen(dst));
	}
	if (dst == NULL)
		return (ft_strlen(src));
	len_src = ft_strlen(src);
	len_dst = 0;
	while (len_dst < size && dst[len_dst] != '\0')
		len_dst++;
	if (len_dst >= size)
		return (size + len_src);
	if (len_src + 1 < size - len_dst)
		len_copy = len_src;
	else
		len_copy = size - len_dst - 1;
	ft_memcpy(dst + len_dst, src, len_copy);
	dst[len_dst + len_copy] = '\0';
	return (len_dst + len_src);
}
