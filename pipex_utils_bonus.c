/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 20:18:41 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/04 15:57:31 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex_bonus.h"

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
	ft_err("close");
	return (0);
}
