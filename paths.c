/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:36:14 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/30 22:53:22 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

char	**free_all(char	**s1)
{
	int	i;

	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			free(s1[i]);
			i++;
		}
		free(s1);
	}
	return (NULL);
}

static char	**finish_paths(char **paths)
{
	int		i;
	char	*temp;

	i = 0;
	if (paths == NULL)
		return (NULL);
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			return (free_all(paths));
		free(paths[i]);
		paths[i] = temp;
		i++;
	}
	return (paths);
}

static char	**path_manual(void)
{
	char		**paths;
	int			i;
	const char	*temp[] = {"/usr/local/sbin/",
		"/usr/local/bin/", "/usr/sbin/", "/usr/bin/", "/sbin/", "/bin/"};

	i = 0;
	paths = malloc(7 * sizeof(char *));
	if (paths == NULL)
		return (NULL);
	while (i < 6)
	{
		paths[i] = ft_strdup(temp[i]);
		if (paths[i] == NULL)
			return (free_all(paths));
		i++;
	}
	paths[i] = NULL;
	return (paths);
}

char	**create_paths(char **envp)
{
	char	**paths;
	int		i;

	i = 0;
	envp = NULL;
	if (envp == NULL)
		return (path_manual());
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (envp[i] == NULL)
		return (NULL);
	paths = ft_split(&envp[i][5], ':');
	paths = finish_paths(paths);
	if (paths == NULL)
	{
		ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ", strerror(ENOMEM), "\n");
		return (NULL);
	}
	return (paths);
}
