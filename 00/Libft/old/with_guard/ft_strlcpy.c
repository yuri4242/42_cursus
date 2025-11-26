/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata  <yikebata@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:59:35 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/16 11:28:36 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dsize)
{
	size_t	copy_len;
	size_t	src_len;

	if (src == NULL)
		return (0);
	src_len = ft_strlen(src);
	if (dst == NULL)
		return (src_len);
	if (dsize == 0)
		return (src_len);
	copy_len = 0;
	if (src_len + 1 < dsize)
		copy_len = src_len;
	else if (dsize != 0)
		copy_len = dsize - 1;
	ft_memcpy(dst, src, copy_len);
	dst[copy_len] = '\0';
	return (src_len);
}
