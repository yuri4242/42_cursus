/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:44:28 by yikebata          #+#    #+#             */
/*   Updated: 2025/11/18 09:26:23 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	fill(char **tab, t_point size, t_point cur, char target)
{
	if (cur.x >= size.x || cur.y >= size.y || cur.x < 0 || cur.y < 0)
		return ;
	if (tab[cur.y][cur.x] == 'F' || tab[cur.y][cur.x] != target)
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x + 1, cur.y}, target);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, target);
	fill(tab, size, (t_point){cur.x - 1, cur.y}, target);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.y][begin.x];
	fill(tab, size, begin, target);
}
