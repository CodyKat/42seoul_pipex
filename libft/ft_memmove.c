/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:43 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/11/10 02:46:07 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*p_dst;
	const unsigned char	*p_src;

	if (dst == NULL || src == NULL)
		return (NULL);
	if (dst > src)
	{
		p_dst = (unsigned char *)(dst + len - 1);
		p_src = (const unsigned char *)(src + len - 1);
		while (len-- > 0)
			*p_dst-- = *p_src--;
	}
	else
	{
		p_dst = (unsigned char *)dst;
		p_src = (const unsigned char *)src;
		while (len-- > 0)
			*p_dst++ = *p_src++;
	}
	return (dst);
}
