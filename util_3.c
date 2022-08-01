/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 03:36:02 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/02 03:39:39 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_error_arguments()
{
	write(2, "too few or too many arguments\n", \
				ft_strlen("too few or too many arguments\n"));
	exit(ERROR);
}
