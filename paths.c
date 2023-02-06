/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 17:36:14 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/06 14:36:36 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

static char	**finish_paths(char **paths)
{
	int		i;
	char	*temp;

	i = 0;
	while (paths[i])
	{
		temp = ft_strjoin(paths[i], "/");
		if (temp == NULL)
			ft_err("malloc");
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
		ft_err("malloc");
	while (i < 6)
	{
		paths[i] = ft_strdup(temp[i]);
		if (paths[i] == NULL)
			ft_err("malloc");
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
	if (envp == NULL)
		return (path_manual());
	while (envp[i] && ft_strncmp(envp[i], "PATH", 4))
		i++;
	if (envp[i] == NULL)
		return (path_manual());
	paths = ft_split(&envp[i][5], ':');
	if (paths == NULL)
		ft_err("malloc");
	paths = finish_paths(paths);
	return (paths);
}
