/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:02:54 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/31 07:47:52 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	temp_file(int check)
{
	int	fd;

	if (check)
	{
		fd = open("here_doc", O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	}
	else
		fd = open("here_doc", O_RDONLY, S_IRUSR | S_IWUSR | S_IRGRP
			| S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 2, "pipex: here_doc: ", strerror(errno));
	return (fd);
}

int	prompt_user(char *s, int fd)
{
	char	*str;

	write(1, "> ", 2);
	str = get_next_line(STDIN_FILENO);
	if (ft_strncmp(s, str, ft_strlen(s)))
	{
		ft_putstr_fd(str, fd);
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	here_doc(int argc, char *argv[], char **paths)
{
	int		tmp_fd;
	int		status;
	char	*s;

	tmp_fd = temp_file(1);
	s = ft_strjoin(*argv, "\n");
	if (s == NULL)
		exit(ENOMEM);
	while (prompt_user(s, tmp_fd));
	free(s);
	close(tmp_fd);
	tmp_fd = temp_file(0);
	status = redirect(&argv[1], paths, argc - 1, tmp_fd);
	free_all(paths);
	if (WIFEXITED(status))
		exit(WEXITSTATUS(status));
	exit(EXIT_FAILURE);
}
