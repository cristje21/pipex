/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/12/30 19:44:10 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(void)
{
	//int fd = open("test.txt", O_CREAT | O_WRONLY | O_APPEND);
	char	line[10] = "123456789";
	int		cpi;
	int		fd[2];
	char	read_buff[80];

	pipe(fd);
	if ((cpi = fork()) == -1)
	{ //something went wrong
		perror("fork");
		exit(1);
	}
	printf("%d, %d\n", fd[0], fd[1]);
	if (cpi == 0)
	{ //child process wants to send, so it writes to the output
		close(fd[0]);
		write(fd[1], line, 9);
	}
	else
	{
		close(fd[1]);
		read(fd[0], read_buff, 9);
		read_buff[9] = '\0';
		printf("%s\n", read_buff);
	}
	return (0);
}