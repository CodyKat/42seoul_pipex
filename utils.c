#include <pipex.h>

void	ft_error(char *message)
{
	perror(message);
	exit(1);
}
