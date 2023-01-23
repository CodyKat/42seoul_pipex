/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:40:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2023/01/24 05:32:24 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	gnl_strchr(char *str, char to_find)
{
	int	len;

	len = 0;
	if (str == 0)
		return (0);
	while (1)
	{
		if (*str == to_find || *str == '\0')
			break ;
		str++;
		len++;
	}
	return (len);
}

void	*gnl_memcpy(void *dst, void *src, size_t n)
{
	unsigned char		*p_dst;
	unsigned char		*p_src;

	if (dst == 0 && src == 0)
		return (0);
	p_dst = dst;
	p_src = src;
	while (n-- > 0)
	{
		*p_dst++ = *p_src++;
	}
	return (dst);
}

char	*gnl_strjoin(char **p_s1, char *s2)
{
	char	*string;
	int		s1_len;
	int		s2_len;

	s1_len = gnl_strchr(*p_s1, '\0');
	s2_len = gnl_strchr(s2, '\0');
	string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	gnl_memcpy(string, *p_s1, s1_len);
	gnl_memcpy(string + s1_len, s2, s2_len);
	string[s1_len + s2_len] = '\0';
	if (*p_s1 != 0)
		free(*p_s1);
	return (string);
}

int	in_newline(char *str)
{
	if (str == 0)
		return (0);
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}
