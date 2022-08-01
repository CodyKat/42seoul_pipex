/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 01:50:05 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/02 03:19:53 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_bzero(void *s, size_t n)
{
	while (n-- > 0)
	{
		*(char *)s = '\0';
		s++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;

	ptr = (void *)malloc(count * size);
	if (ptr == NULL)
		exit(MALLOC_ERROR);
	ft_bzero(ptr, count * size);
	return (ptr);
}

void	*ft_memset(void *dst, int c, size_t len)
{
	unsigned char	*p;

	p = dst;
	while (len-- > 0)
	{
		*p++ = c;
	}
	return (dst);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*s++ != '\0')
		len++;
	return (len);
}
