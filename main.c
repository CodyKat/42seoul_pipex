/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaemjeon <jaemjeon@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:03:31 by jaemjeon          #+#    #+#             */
/*   Updated: 2022/06/29 20:16:22 by jaemjeon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		count;
	int		pipe_fd[2];
	char	*file_name[2];
	char	**cmd_table;

	cmd_table = (char **)malloc(sizeof(char *) * (argc - 3));
	file_name[0] = argv[1];
	file_name[1] = argv[argc - 1];
	count = 0;
	while (count < argc -3)
	{
		cmd_table[count] = argv[count + 1];
		count++;
	}
	count = 0
	while (count < argc - 3)
	{
		pipe(pipe_fd);
		fork();
		close(pipe_fd[0]);
		count++;
	}
}
