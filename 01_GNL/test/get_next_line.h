/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yikebata <yikebata@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:17:39 by yikebata          #+#    #+#             */
/*   Updated: 2025/10/17 16:42:11 by yikebata         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 32

# include <unistd.h>
# include <stdlib.h>
/*
//get_next_line.c
char	*extract_line(char const *leftover);
char	*update_leftover(char *leftover);
int		read_one_line(int fd, char **leftover);
char	*process_leftover(char **leftover);
*/
char	*get_next_line(int fd);
//get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_memcpy(void *dest, const void *src, size_t n);
size_t	ft_strlcpy(char *dst, const char *src, size_t dsize);
char	*gnl_strjoin(char *s1, char *s2);

#endif
