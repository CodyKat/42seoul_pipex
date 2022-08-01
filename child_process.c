/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 13:39:46 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/07/18 14:52:14 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	first_child_process(t_info *info, int *fd, char **envp)
{
	int			infile_fd;
	char		**child_argv;
	extern char	**environ;

	child_argv = (char **)malloc(sizeof(char *) * 2);
	child_argv[0] = info->command1;
	child_argv[1] = NULL;
	infile_fd = open(info->infile, O_RDONLY);
	dup2(infile_fd, 0);
	dup2(fd[1], 1);
	execve("/bin/ls", child_argv, environ);
}

void	second_child_process(t_info *info, int *fd, char **envp)
{
	char	**child_argv;
	int		outfile_fd;

	child_argv = (char **)malloc(sizeof(char *) * 2);
	child_argv[0] = info->command2;
	child_argv[1] = NULL;
	outfile_fd = open(info->outfile, O_WRONLY);
	dup2(fd[0], 0);
	dup2(outfile_fd, 1);
	execve("/bin/cat", child_argv, envp);
}
