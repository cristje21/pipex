/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   access.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/05 15:10:48 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/28 22:38:44 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

char	**free_all(char	**s1, char **s2)
{
	int	i;

	i = 0;
	if (s1)
	{
		while (s1[i])
			free(s1[i++]);
		free(s1);
	}
	i = 0;
	if (s2)
	{
		while (s2[i])
			free(s2[i++]);
		free(s2);
	}
	return (NULL);
}

static char	**create_paths(char **envp)
{
	char	**paths;
	char	*temp;
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (envp[i] == NULL)
		exit(151);
	paths = ft_split(&envp[i][5], ':');
	if (paths == NULL)
		exit(ENOMEM);
	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			exit(ENOMEM);
		free(paths[i]);
		paths[i] = temp;
		i++;
	}
	return (paths);
}

static char	**check_access(char **result, char **paths)
{
	char	*temp;
	int		i;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], result[0]);
		if (temp == NULL)
			exit(ENOMEM);
		if (!access(temp, F_OK))
		{
			free(result[0]);
			result[0] = temp;
			free_all(paths, NULL);
			return (result);
		}
		free(temp);
		i++;
	}
	exit(150);
}

char	**get_command_acces(char *command, char **envp)
{
	char	**result;
	char	**paths;

	paths = create_paths(envp);
	result = split_arg(command);
	return (check_access(result, paths));
}
