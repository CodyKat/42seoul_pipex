/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:57:28 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/02 04:14:43 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;

	src_len = ft_strlen(src);
	if (dstsize == 0)
		return (src_len);
	while (--dstsize > 0)
	{
		if (*src == '\0')
			break ;
		*dst++ = *src++;
	}
	*dst = '\0';
	return (src_len);
}

static int	ft_count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s != '\0')
	{
		while (*s == c)
			s++;
		if (*s == '\0')
			return (count);
		while (*s != '\0' && *s != c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_alloc_string(char **dst, const char *src, char del)
{
	int		len;

	len = 0;
	while (*src == del)
		src++;
	while (*src != del && *src != '\0')
	{
		src++;
		len++;
	}
	*dst = (char *)ft_calloc(sizeof(char), (len + 1));
	src -= len;
	ft_strlcpy(*dst, src, len + 1);
	return ((char *)(src + len - 1));
}

char	**ft_split(const char *s, char c)
{
	char	**table;
	int		word_count;
	int		idx;

	idx = 0;
	word_count = ft_count_words(s, c);
	table = (char **)ft_calloc(sizeof(char *), (word_count + 1));
	while (idx < word_count)
	{
		s = ft_alloc_string(&table[idx], s, c);
		s++;
		idx++;
	}
	return (table);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*u_s1;
	unsigned char	*u_s2;

	u_s1 = (unsigned char *)s1;
	u_s2 = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*u_s1 > *u_s2)
			return (1);
		else if (*u_s1 < *u_s2)
			return (-1);
		else if (*u_s1 == '\0' && *u_s2 == '\0')
			return (0);
		u_s1++;
		u_s2++;
	}
	return (0);
}
