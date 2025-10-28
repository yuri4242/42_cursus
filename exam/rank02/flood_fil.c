/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fil.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 08:44:28 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/28 08:54:02 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static void	fill(char **tab, t_point size, t_point cur, char target)
{
	if (cur.y < 0 || cur.x < 0 || cur.y >= size.y || cur.x >= size.x)
		return ;
	if (tab[cur.x][cur.y] == 'F' || tab[cur.x][cur.y] = target)
		return ;
	fill(tab, size, (t_point){cur.x, cur.y - 1}, taget);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, target);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, target);
	fill(tab, size, (t_point){cur.x - 1, cur.y}, target);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target;

	target = tab[begin.x][begin.y];
	fill(tab, size, begin, target);
}
