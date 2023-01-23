/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 19:03:53 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/11/10 04:10:48 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <errno.h>
#define BASE 10

static int	is_space(const char *c)
{
	if ((9 <= *c && *c <= 13) || *c == ' ')
		return (TRUE);
	return (FALSE);
}

static const char	*skip_space_detmin_sign(const char *str, int *sign)
{
	while (is_space(str))
		str++;
	if (*str == '+')
	{
		str++;
		*sign = 1;
	}
	else if (*str == '-')
	{
		str++;
		*sign = -1;
	}
	else
		*sign = 1;
	return (str);
}

static int	check_out_of_range(long long result, int sign)
{
	if (sign == 1 && result > INT_MAX)
	{
		errno = ERANGE;
		return (TRUE);
	}
	else if (sign == -1 && result < INT_MIN)
	{
		errno = ERANGE;
		return (TRUE);
	}
	return (FALSE);
}

int	ft_atoi(const char *str)
{
	long long	result;
	int			sign;

	result = 0;
	str = skip_space_detmin_sign(str, &sign);
	while (ft_isalnum(*str))
	{
		result *= 10;
		result += *str - '0';
		if (check_out_of_range(result, sign))
		{
			if (sign == 1)
				return (INT_MAX);
			else
				return (INT_MIN);
		}
		str++;
	}
	result *= sign;
	return ((int)result);
}
