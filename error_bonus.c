
#include "pipex_bonus.h"
#include "libft/libft.h"

void	ft_err(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(s);
	exit(errno);
}

char	**free_all(char	**s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}
