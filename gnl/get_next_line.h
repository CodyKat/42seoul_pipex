/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:51:49 by jaemjeon          #+#    #+#             */
/*   Updated: 2023/01/24 05:37:52 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# ifndef FD_MAX
#  define FD_MAX 256
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
int		gnl_strchr(char *str, char to_find);
void	*gnl_memcpy(void *dst, void *src, size_t n);
char	*gnl_strjoin(char **p_s1, char *s2);
int		in_newline(char *str);

#endif
