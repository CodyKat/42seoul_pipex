#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libft/libft.h"
#include "gnl/get_next_line.h"
#include <stdio.h>
#include <signal.h>

void	ft_error(char *message);

typedef struct s_info
{
	int		is_heredoc;
	char	*infile;
	int		fd_infile;
	char	*outfile;
	int		fd_outfile;
	char	*limiter;
	int		cmd_cnt;
	char	**cmd;
	char	**path;

}	t_info;
