/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   paths.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 17:36:14 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/30 19:59:39 by cvan-sch      ########   odam.nl         */
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
			free(s1[i++]);
		free(s1);
	}
	return (NULL);
}

static char	**finish_paths(char **paths)
{
	int		i;
	char	*temp;

	i = 0;
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
			free_all(paths);
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
	if (paths == NULL)
	{
		ft_putnstr_fd(STDERR_FILENO, 2, "pipex: ", strerror(ENOMEM));
		return (NULL);
	}
	paths = finish_paths(paths);
	if (paths == NULL)
		return (NULL);
	return (paths);
}
