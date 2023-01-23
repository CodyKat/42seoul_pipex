#include "pipex.h"

extern char	**environ;

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
		info->limiter = argv[2];
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

void	ft_execve(t_info *info, int cmd_cnt)
{
	char	**sp;
	int		mode;
	char	*access_name;
	char	*tmp_string;
	int		i;

	mode = F_OK;
	sp = ft_split(info->cmd[cmd_cnt], ' ');
	i = -1;
	while (info->path[++i])
	{
		tmp_string = ft_strjoin(info->path[i], "/");
		access_name = ft_strjoin(tmp_string, sp[0]);
		free(tmp_string);
		if (access(access_name, mode) == 0)
		{
			free(sp[0]);
			sp[0] = access_name;
			execve(sp[0], sp, environ);
			return ;
		}
		free(access_name);
	}
}

int	first_middle_process(t_info *info, int cmd_cnt)
{
	int		fd[2];
	pid_t	pid;

	pipe(fd);
	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		dup2(info->fd_infile, 0);
		ft_execve(info, cmd_cnt);
		ft_error("command not found");
	}
	close(fd[1]);
	close(info->fd_infile);
	info->fd_infile = fd[0];
	return (pid);
}


int	last_process(t_info *info)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		dup2(info->fd_infile, 0);
		dup2(info->fd_outfile, 1);
		ft_execve(info, info->cmd_cnt - 1);
		ft_error("command not found");
	}
	close(info->fd_infile);
	close(info->fd_outfile);
	return (pid);
}

void	kill_all_child(int *child_pids, int child_cnt)
{
	int	i;

	i = -1;
	while (++i < child_cnt)
		kill(child_pids[i], SIGKILL);
}

int	main_loop(t_info *info)
{
	int	i;
	int	*child_pids;
	int	exit_status;

	child_pids = malloc(sizeof(int) * info->cmd_cnt);
	i = -1;
	while (++i < info->cmd_cnt)
	{
		if (i == info->cmd_cnt - 1)
			child_pids[i] = last_process(info);
		else
			child_pids[i] = first_middle_process(info, i);
		if (child_pids[i] == -1)
		{
			kill_all_child(child_pids, i);
			if (info->is_heredoc)
				unlink("tmpfile");
			ft_error("fork error");
		}
	}
	i = -1;
	while (++i < info->cmd_cnt)
		waitpid(child_pids[i], &exit_status, 0);
	return (exit_status);
}

int	read_heredoc(t_info *info)
{
	char const *	tmpfile_name = "tmpfile";
	int				fd_heredoc;
	char			*line;

	fd_heredoc = open(tmpfile_name, O_RDWR | O_CREAT, 0644);
	if (fd_heredoc == -1)
		ft_error("heredoc tmpfile open error");
	while (TRUE)
	{
		line = get_next_line(1);
		if (line == NULL)
		{
			write(1, "EOF detacted", ft_strlen("EOF detacted"));
			unlink(tmpfile_name);
			exit(0);
		}
		else if (ft_strncmp(line, info->limiter, ft_strlen(info->limiter)) == 0 \
					&& line[ft_strlen(line) - 1] == '\n')
		{
			free(line);
			return (fd_heredoc);
		}
		write(fd_heredoc, line, ft_strlen(line));
		free(line);
	}
}

int	get_path(t_info *info)
{
	int	i;

	i = -1;
	while (environ[++i])
	{
		if (ft_strncmp(environ[i], "PATH=", ft_strlen("PATH=")) == 0)
		{
			info->path = ft_split(environ[i], ':');
			return (0);
		}
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		exit_status;

	parse(argc, argv, &info);
	if (info.is_heredoc)
		info.fd_infile = read_heredoc(&info);
	else
		info.fd_infile = open(info.infile, O_RDONLY);
	if (info.fd_infile == -1)
		ft_error("infile error");
	info.fd_outfile = open(info.outfile, O_WRONLY | O_CREAT, 0644);
	if (info.fd_outfile == -1)
	{
		if (info.is_heredoc)
			unlink("tmpfile");
		ft_error("outfile error");
	}
	if (get_path(&info))
	{
		if (info.is_heredoc)
			unlink("tmpfile");
		ft_error("error in get path");
	}
	exit_status = main_loop(&info);
	if (info.is_heredoc)
		unlink("tmpfile");
	return (exit_status);
}
