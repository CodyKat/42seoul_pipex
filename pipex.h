#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include "libft/libft.h"
#include <stdio.h>

void	ft_error(char *message);

typedef struct s_info
{
	int		is_heredoc;
	char	*infild;
	char	*outfile;
	char	*limiter;
	int		cmd_cnt;
	char	**cmd;

}	t_info;
