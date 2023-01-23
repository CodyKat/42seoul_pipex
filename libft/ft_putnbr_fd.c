/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 13:24:36 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 03:12:48 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	*string_n;

	string_n = ft_itoa(n);
	if (string_n == NULL)
		return ;
	write(fd, string_n, ft_strlen(string_n));
	free(string_n);
}
