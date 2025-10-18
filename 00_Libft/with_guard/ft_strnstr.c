/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata  <yikebata@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:59:35 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/16 14:28:25 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	len_lit;

	if (big == NULL || little == NULL)
		return (NULL);
	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	len_lit = ft_strlen(little);
	while (i < len && big[i] != '\0' && i <= len - len_lit)
	{
		if (ft_memcmp(big + i, little, len_lit) == 0)
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
