/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   access_bonus.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 15:10:48 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/02/14 15:48:41 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

static char	**check_access(char **result, char **paths)
{
	char	*temp;
	int		i;

	i = 0;
	if (!access(result[0], X_OK))
		return (free_all(paths), result);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], result[0]);
		if (temp == NULL)
			ft_err("malloc");
		if (!access(temp, X_OK))
		{
			free(result[0]);
			result[0] = temp;
			free_all(paths);
			return (result);
		}
		free(temp);
		i++;
	}
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ",
		result[0], ": command not found\n");
	exit(127);
}

char	**get_command_acces(char *command, char *envp[])
{
	char	**result;
	char	**paths;

	paths = create_paths(envp);
	result = split_arg(command);
	return (check_access(result, paths));
}
