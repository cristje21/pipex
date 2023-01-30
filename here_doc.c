/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   here_doc.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 20:02:54 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/30 20:02:55 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	here_doc(char *limiter)
{
	int		tmp_fd;
	char	*str;
	char	*s;

	tmp_fd = open("here_doc", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (tmp_fd == -1)
	{
		perror("tmp_fd");
		exit(ENOENT);
	}
	s = ft_strjoin(limiter, "\n");
	write(1, "> ", 2);
	str = get_next_line(STDIN_FILENO);
	while (ft_strncmp(s, str, ft_strlen(s)))
	{
		ft_putstr_fd(str, tmp_fd);
		free(str);
		write(1, "> ", 2);
		str = get_next_line(STDIN_FILENO);
	}
	free(str);
	free(s);
	return (tmp_fd);
}
