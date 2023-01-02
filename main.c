/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/02 12:47:20 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_execve(void)
{
	char	*argv[] = {"/bin/grep", "YO", NULL};
	int		pid;
	int		fd, bytes_read;
	char	buff[10];

	fd = open("test", O_RDWR);
	if (fd == -1)
		return ;
	bytes_read = 10;
	while (bytes_read == 10)
	{
		bytes_read = read(fd, buff, sizeof(buff));
		if (bytes_read == -1)
			return ;
		write(1, buff, bytes_read);
	}
	close(fd);
	execve(argv[0], argv, NULL);
	printf("\nthis id > %d, got here!\n", pid);
}

int	main(void)
{
	test_execve();
	//int fd = open("test.txt", O_CREAT | O_WRONLY | O_APPEND);
	// char	line[10] = "123456789";
	// int		cpi;
	// int		fd[2];
	// char	read_buff[80];

	// pipe(fd);
	// if ((cpi = fork()) == -1)
	// { //something went wrong
	// 	perror("fork");
	// 	exit(1);
	// }
	// printf("%d, %d\n", fd[0], fd[1]);
	// if (cpi == 0)
	// { //child process wants to send, so it writes to the output
	// 	close(fd[0]);
	// 	write(fd[1], line, 9);
	// }
	// else
	// {
	// 	close(fd[1]);
	// 	read(fd[0], read_buff, 9);
	// 	read_buff[9] = '\0';
	// 	printf("%s\n", read_buff);
	// }
	// return (0);
}