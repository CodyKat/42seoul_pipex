/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:04:16 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/19 03:59:16 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_sign(long long_num)
{
	if (long_num >= 0)
		return (1);
	else
		return (-1);
}

static int	ft_calcul_len_of_long(long long_num)
{
	int	len;

	len = 0;
	if (long_num == 0)
		return (1);
	if (long_num < 0)
	{
		len++;
		long_num *= -1;
	}
	while (long_num)
	{
		len++;
		long_num /= 10;
	}
	return (len);
}

void	ft_fill_arr(char *output, long long_num, int num_len, int sign)
{
	if (long_num < 0)
		long_num *= -1;
	output[num_len] = '\0';
	while (--num_len > 0)
	{
		output[num_len] = (long_num % 10) + '0';
		long_num /= 10;
	}
	if (sign == 1)
		output[0] = long_num + '0';
	else
		output[0] = '-';
}

char	*ft_itoa(int c)
{
	long	long_num;
	int		sign;
	int		num_len;
	char	*output;

	long_num = c;
	sign = ft_find_sign(long_num);
	num_len = ft_calcul_len_of_long(long_num);
	output = (char *)malloc(sizeof(char) * (num_len + 1));
	if (output == NULL)
		return (NULL);
	ft_fill_arr(output, long_num, num_len, sign);
	return (output);
}
