/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmds2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/22 14:35:03 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/23 23:25:24 by yu-ri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

void	state_parser(char c, int *state)
{
	if (c == '\'' && *state != D_QUOTE)
	{
		if (*state == S_QUOTE)
			*state = NORMAL;
		else
			*state = S_QUOTE;
	}
	if (c == '"' && *state != S_QUOTE)
	{
		if (*state == D_QUOTE)
			*state = NORMAL;
		else
			*state = D_QUOTE;
	}
}
