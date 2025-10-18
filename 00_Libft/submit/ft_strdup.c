/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata  <yikebata@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 08:59:35 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/18 23:50:22 by yu-ri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		len_s;
	char	*ptr;

	len_s = ft_strlen(s);
	ptr = malloc(sizeof(char) * (len_s + 1));
	if (ptr == NULL)
		return (NULL);
	ft_memcpy(ptr, s, len_s + 1);
	return (ptr);
}
