/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 15:40:56 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/03/25 21:36:05 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchr(char *str, char to_find)
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

void	*ft_memcpy(void *dst, void *src, size_t n)
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

char	*ft_strjoin(char **p_s1, char *s2)
{
	char	*string;
	int		s1_len;
	int		s2_len;

	s1_len = ft_strchr(*p_s1, '\0');
	s2_len = ft_strchr(s2, '\0');
	string = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	ft_memcpy(string, *p_s1, s1_len);
	ft_memcpy(string + s1_len, s2, s2_len);
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
