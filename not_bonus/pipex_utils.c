/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:18:41 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/01 16:29:17 by cristje          ###   ########.fr       */
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
		ft_err("malloc: ");
	ft_strlcpy(new, s + 1, len - 1);
	free(s);
	return (new);
}

int	close_pipe(int p[])
{
	if (close(p[0]) != -1 && close(p[1]) != -1)
		return (1);
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: close: ", strerror(errno), "\n");
	exit(errno);
}

void	ft_err(char *s)
{
	ft_putnstr_fd(STDERR_FILENO, 4, "pipex: ", s, strerror(errno), "\n");
	exit(errno);
}

int	pipe_and_fork(int p[])
{
	pid_t	pid;

	if (pipe(p) == -1)
		ft_err("pipe");
	pid = fork();
	if (pid == -1)
		ft_err("fork");
	return (pid);
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
