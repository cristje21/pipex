/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   access.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 15:10:48 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/30 22:12:19 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

static char	**check_access(char **result, char **paths)
{
	char	*temp;
	int		i;

	i = 0;
	if (!access(result[0], F_OK))
		return (result);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], result[0]);
		if (temp == NULL)
			exit(ENOMEM);
		if (!access(temp, F_OK))
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

char	**get_command_acces(char *command, char **paths)
{
	char	**result;

	result = split_arg(command);
	return (check_access(result, paths));
}
