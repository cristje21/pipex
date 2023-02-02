/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:18:41 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/02 00:16:30 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex_bonus.h"

int	append(char *argv[])
{
	while (ft_strncmp(*argv, "./pipex", 7)
		&& ft_strncmp(*argv, "here_doc", 8)
		&& ft_strncmp(*argv, "./a.out", 7))
		argv--;
	if (!ft_strncmp(*argv, "here_doc", 8))
		return (0);
	return (1);
}

char	*ft_trim_quote(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len - 1);
	if (new == NULL)
		ft_err("malloc");
	ft_strlcpy(new, s + 1, len - 1);
	free(s);
	return (new);
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

int	close_pipe(int p[])
{
	if (close(p[0]) != -1 && close(p[1]) != -1)
		return (1);
	perror("pipex: close");
	exit(errno);
}
