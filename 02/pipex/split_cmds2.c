/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:35:03 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/22 17:40:57 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	state_parser(const char **s, int *state)
{
	if (**s == '\'' && *state != D_QUOTE)
	{
		if (*state == S_QUOTE)
			*state = NORMAL;
		else
			*state = S_QUOTE;
	}
	else if (**s == '"' && *state != S_QUOTE)
	{
		if (*state == D_QUOTE)
			*state = NORMAL;
		else
			*state = D_QUOTE;
	}
}
