/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:31:54 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/08/02 04:13:31 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**get_env_path(char *envp[])
{
	while (*envp != 0 && ft_strncmp("PATH=", *envp, 5) != 0)
		envp++;
	return (ft_split((*envp) + 5, ':'));
}

void	parsing(t_info *info, int argc, char *argv[], char *envp[])
{
	int	index;

	index = -1;
	if (ft_strncmp("here_doc", argv[1], ft_strlen("here_doc") + 1) == 0)
	{
		if (argc != 6)
			ft_error_arguments();
		info->is_heredoc = TRUE;
		info->command_count = 2;
		info->limiter = argv[2];
		info->command_arr = (char **)ft_calloc(sizeof(char *), 2);
		info->command_arr[0] = argv[3];
		info->command_arr[1] = argv[4];
		info->outfile_name = argv[5];
	}
	else
	{
		info->infile_name = argv[1];
		info->command_count = argc - 3;
		info->command_arr = (char **)ft_calloc(sizeof(char *), argc - 3);
		while (++index)
			info->command_arr[index] = argv[index + 2];
		info->outfile_name = argv[argc - 1];
	}
	info->env_path = get_env_path(envp);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_info	info;

	if (argc < 5)
		ft_error_arguments();
	parsing(&info, argc, argv, envp);
	if (info.is_heredoc == FALSE)
		processing_with_no_heredoc(&info);
	else
		processing_with_heredoc(&info);
	return (0);
}
