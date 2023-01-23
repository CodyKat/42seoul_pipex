/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:31 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 03:03:03 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	to_find;

	ptr = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (n-- > 0)
	{
		if (*ptr == to_find)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}
