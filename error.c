/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/02/02 14:44:56 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/02/02 15:44:51 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
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

void	initial_error(int argc)
{
	if (argc != 5)
	{
		ft_putnstr_fd(STDIN_FILENO, 2, "format: ./pipex [infile] [cmd1]",
			" [cmd2] [...] [outfile]\n");
		exit(EXIT_FAILURE);
	}
}
