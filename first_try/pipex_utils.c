/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 20:18:41 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/29 21:06:29 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

char	*ft_trim_quote(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len - 1);
	if (new == NULL)
		exit(ENOMEM);
	ft_strlcpy(new, s + 1, len - 1);
	free(s);
	return (new);
}

static void put_first_word(char *s, char *msg)
{
	int	i;

	i = 0;
	while (s[i] != ' ' && s[i])
		i++;
	if (write(2, s, i) == -1 || write(2, ": ", 2) == -1 ||
		write(2, msg, ft_strlen(msg)) == -1)
		exit(errno);
}

void	check_status(int exit_status, char *program)
{
	int	status;

	if (!WIFEXITED(exit_status))
		return ;
	status = WEXITSTATUS(exit_status);
	if (!status)
		return ;
	if (status == ENOENT)
		ft_putstr_fd("pipex: ", STDERR_FILENO);
	if (status == 150)
		put_first_word(program, "command not found\n");
	else if (status == 151)
		put_first_word(program, "no environment (path) found\n");
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		ft_putstr_fd(program, STDERR_FILENO);
		ft_putendl_fd(strerror(status), STDERR_FILENO);
	}
}

void	close_pipe(int pipe[])
{
	close(pipe[0]);
	close(pipe[1]);
}

void	ft_err(char *s)
{
	perror(s);
	exit(errno);
}
