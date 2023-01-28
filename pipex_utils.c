/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 20:18:41 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/28 22:23:39 by cvan-sch      ########   odam.nl         */
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

void	check_status(int exit_status)
{
	int	status;

	if (!WIFEXITED(exit_status))
		return ;
	status = WEXITSTATUS(exit_status);
	if (!status)
		return ;
	else if (status == 150)
		ft_putstr_fd("pipex: command not found\n", STDERR_FILENO);
	else if (status == 151)
		ft_putstr_fd("pipex: no environment\n", STDERR_FILENO);
	else
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
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

void	print_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		ft_printf("%s\n", arr[i]);
		i++;
	}
}
