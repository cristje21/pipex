#include "pipex.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	here_doc(char *argv[], int argc)
{
	char	*limiter;
	int		temp_fd;

	temp_fd = open(".", O_TMPFILE | O_RDWR, S_IRUSR | S_IWUSR);
	if (temp_fd == -1)
	{
		ft_printf("something went wrong\n");
		perror("perror");
		exit(23);
	}
	limiter = *argv;
	ft_printf("argc :%d, limiter: %s\n", argc, limiter);
	return (0);
}