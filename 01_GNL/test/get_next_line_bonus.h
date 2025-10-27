/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:17:39 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/24 12:48:55 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_fds
{
	int				fd;
	char			*leftover;
	struct s_fds	*next;
}	t_fds;

//get_next_line.c
char	*get_next_line(int fd);

//get_next_line_utils.c
size_t	gnl_strlen(const char *s);
char	*gnl_strchr(const char *s, int c);
void	*gnl_memcpy(void *dest, const void *src, size_t n);
size_t	gnl_strlcpy(char *dst, const char *src, size_t dsize);
char	*gnl_strjoin(char *s1, char *s2);

#endif
