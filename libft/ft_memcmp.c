/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:35 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 03:20:02 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*chr_s1;
	const unsigned char	*chr_s2;

	chr_s1 = s1;
	chr_s2 = s2;
	while (n-- > 0)
	{
		if (*chr_s1 != *chr_s2)
			return (*chr_s1 - *chr_s2);
		chr_s1++;
		chr_s2++;
	}
	return (0);
}
