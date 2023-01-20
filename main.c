/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/20 21:49:37 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

int	execute(int argc, char *argv[], char *envp[])
{
	int		p[2];
	int		pid;
	char	**command;
	int		fd;
	int		status, stat;

	status = 99;
	stat = 888;
	if (pipe(p) == -1)
		return (perror("pipe"), -1);
	pid = fork();
	if (pid == -1)
		return (perror("fork"), -1);
	if (pid == 0)
	{
		fd = open(argv[0], O_RDONLY);
		if (fd == -1)
		{
			perror("fd: child");
			exit (errno);
		}
		dup2(fd, 0);
		command = get_command_acces(argv[1], envp);
		if (command == NULL)
			exit(1);
		close(p[0]);
		dup2(p[1], 1);
		close(p[1]);
		execve(command[0], command, NULL);
	}
	else
		waitpid(pid, &status, 0);
	pid = fork();
	if (pid == -1)
		return (-1);
	if (pid == 0)
	{
		fd = open(argv[3], O_WRONLY);
		if (fd == -1)
		{
			printf("something went wrong in the second process\n");
			exit(errno);
		}
		command = get_command_acces(argv[2], envp);
		if (command == NULL)
			return (-1);
		close(p[1]);
		dup2(p[0], 0);
		close(p[0]);
		dup2(fd, 1);
		close(fd);
		execve(command[0], command, NULL);
	}
	close(p[0]);
	close(p[1]);
	waitpid(pid, NULL, 0);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 3)
	{
		printf("%d arguments is too little.\n", argc - 1);
		return (0);
	}
	if (execute(argc - 1, &argv[1], envp) == -1)
		printf("something went wrong!\n");
	printf("main process executed and returning...\n");
	return (0);
}

/*
	check if there are atleast 4 arguments excluding the binary;
	after that check if the first argument is equal to here_doc;
	if not open the file and read from it using the first command;
	then go into a function that takes care of all the commands and piping;
	evantually open and create the last file and redirect the output from the
	last output into that;

	open the first file
	do the command with that as input
	then go in a loop and make the output of the command the writing end of the file
*/
