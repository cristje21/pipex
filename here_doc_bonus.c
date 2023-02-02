/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:02:54 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/02 09:51:13 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

static int	temp_file(void)
{
	int	fd;

	fd = open("here_doc", O_WRONLY | O_CREAT | O_EXCL, 0600);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 2, "pipex: here_doc: ", strerror(errno));
	return (fd);
}

static int	prompt_user(char *s, int fd)
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

int	here_doc(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		status;
	char	*s;

	fd = temp_file();
	s = ft_strjoin(*argv, "\n");
	if (s == NULL)
		exit(ENOMEM);
	while (prompt_user(s, fd))
		;
	free(s);
	close(fd);
	fd = open("here_doc", O_RDONLY);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 3, "pipex: here_doc: ",
			strerror(errno), "\n");
	unlink("here_doc");
	status = redirect(&argv[1], envp, argc - 1, fd);
	exit(status);
}
