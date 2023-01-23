#include <pipex.h>

void	parse(int argc, char *argv[], t_info *info)
{
	int	i;

	i = -1;
	if (argc < 5)
		ft_error("too few argc");
	if (ft_strncmp(argv[1], "here_doc", ft_strlen("here_doc") + 1) == 0)
	{
		info->is_heredoc = TRUE;
		info->cmd_cnt = argc - 4;
		info->limiter = argv[1];
		info->cmd = malloc(sizeof(char *) * info->cmd_cnt);
		while (++i < info->cmd_cnt)
			info->cmd[i] = argv[i + 3];
		info->outfile = argv[argc - 1];
	}
	else
	{
		info->is_heredoc = FALSE;
		info->cmd_cnt = argc - 3;
		info->infile = argv[1];
		info->cmd = malloc(sizeof(char *) * info->cmd_cnt);
		while (++i < info->cmd_cnt)
			info->cmd[i] = argv[i + 2];
		info->outfile = argv[argc - 1];
	}
}

int	main_loop(t_info *info)
{
	if ()
}

int	read_heredoc(t_info *info)
{
	int	fd_heredoc;

	fd_heredoc = open("tmpfile", O_WRONLY, 0644);
	if (fd_heredoc == -1)
		ft_error("heredoc tmpfile open error");
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		fd_infile;

	parse(argc, argv, &info);
	if (info.is_heredoc)
		fd_infile = read_heredoc(&info);
	else
		fd_infile = open(info.infile, O_RDONLY);
	if (fd_infile == -1)
		ft_error("infile error");
	else
		return (main_loop(&info));
}
