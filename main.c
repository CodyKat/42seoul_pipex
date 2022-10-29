#include "pipex.h"
#define	CMD_SIZE 3

void	ft_error(char *message, int exit_status)
{
	write(2, message, strlen(message));
	write(2, "\n", 1);
	exit(exit_status);
}

void	parsing(t_info *info, int argc, char *argv[])
{
	int	i, j;

	i = 0;
	if (argc < 5)
		ft_error("argc error", 1);
	while ((argc > i * 2 + 1) && strcmp(argv[2 * i + 1], "here_doc") == 0)
		i++;
	info->heredoc_count = i;
	info->limiter = (char **)calloc(sizeof(char *), info->heredoc_count + 1);
	i = 0;
	while (i < info->heredoc_count)
	{
		info->limiter[i] = argv[2 * (i + 1)];
		i++;
	}
	if (info->heredoc_count == 0)
	{
		info->infile_name = argv[1];
		info->infile = open(info->infile_name, O_RDONLY);
		if (info->infile == 0)
			ft_error("error open infile", 1);
	}
	else
	{
		info->infile_name = argv[info->heredoc_count * 2 + 1];
		info->infile = open(info->infile_name, O_RDONLY);
		if (info->infile == 0)
			ft_error("error open infile", 1);
	}
	i = info->heredoc_count * 2 + 1;
	j = 0;
	info->commands = (char **)calloc(sizeof(char *), argc - i + 1);
	while (i < argc - 1)
	{
		info->commands[j] = argv[i];
		i++;
		j++;
	}
	info->outfile_name = argv[argc - 1];
	info->outfile = open(info->outfile_name, O_RDONLY);
	if (info->outfile == 0)
		ft_error("error open outfile", 1);
}

void	print_info(t_info *info)
{
	int	i;

	i = 0;
	printf("commands :\n");
	while (info->commands[i])
	{
		printf("[%d] : %s\n", i, info->commands[i]);
		i++;
	}
	i = 0;
	printf("heredoc_count : %d\n", info->heredoc_count);
	while (info->limiter[i])
	{
		printf("[%d] : %s\n", i, info->limiter[i]);
		i++;
	}
	printf("infile : [name] = %s, [fd] = %d\n", info->infile_name, info->infile);
	printf("outfile : [name] = %s, [fd] = %d\n", info->outfile_name, info->outfile);
}

void	init_cmd_arr(t_cmd *cmd_arr, int cmd_size)
{
	int i;

	i = 0;
	if (cmd_size > i)
	{
		cmd_arr[0].file = "ls";
		cmd_arr[0].argv[0] = "ls";
		cmd_arr[0].argv[1] = NULL;
		i++;
	}
	while (i < cmd_size)
	{
		cmd_arr[i].file = "cat";
		cmd_arr[i].argv[0] = "cat";
		cmd_arr[i].argv[1] = NULL;
		i++;
	}
}

void	first_process(t_cmd *cmd_arr, int *fd, int *last_output_fd)
{
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		dup2(fd[1], 1);
	}
	else
	{
		
	}

}

void	middle_process(t_cmd *cmd_arr, int *fd, int *last_output_fd)
{

}

void	last_process(t_cmd *cmd_arr, int *fd, int *last_output_fd)
{

}

void	run_pipex(t_cmd *cmd_arr)
{
	int	i;
	int	fd[2];
	int	last_output_fd;

	i = 0;
	// CMD_SIZE == 1인 경우는 의미가 없으니 무시함
	while (i < CMD_SIZE)
	{
		if (i == 0)
			first_process(cmd_arr, fd, last_output_fd);
		else if (i == CMD_SIZE - 1)
			last_process(cmd_arr, fd, last_output_fd);
		else
			middle_process(cmd_arr, fd, last_output_fd);
		i++;
	}
}

int main(int argc, char *argv[], char *envp[])
{
	// t_info	info;
	// memset(&info, 0 , sizeof(t_info));
	// parsing(&info, argc, argv);
	// print_info(&info);
	t_cmd	cmd_arr[CMD_SIZE];

	init_cmd_arr(cmd_arr, CMD_SIZE);
	run_pipex(&cmd_arr);
	return (0);
}