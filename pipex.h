#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#define	CMD_SIZE 100

typedef	struct s_info
{
	char	**commands;
	int		heredoc_count;
	char	**limiter;
	char	*infile_name;
	char	*outfile_name;
	int		infile;
	int		outfile;
}	t_info;

typedef struct s_cmd
{
	char	*file;
	char	**argv;
}	t_cmd;
