/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/17 19:37:41 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

int	do_first_command(char *argv[], char *envp[], int fd, int *my_pipe)
{
	char **command;

	command = get_command_acces(argv[1], envp);
	if (command == NULL)
	{
		perror("command");
		exit(1);
	}
	dup2(fd, 0);
	dup2(my_pipe[1], 1);
	close(my_pipe[0]);
	if (execve(command[0], command, NULL) == -1)
		exit(1);
	return 1;
}

void	do_child(char *arg, char *envp[], int p[], int fd)
{
	char buff[100];

	read(p[0], buff, 100);
	printf("%s!\n", buff);
	exit(0);
}

int	execute(int argc, char *argv[], char *envp[])
{
	int	p[2];
	int	fd;
	int	pid;
	int	i, status;

	i = 0;
	fd = open(argv[0], O_RDONLY);
	if (fd == -1)
		return (perror("file"), -1);
	while (i < argc)
	{
		if (pipe(p) == -1)
			return (perror("pipe"), -1);
		dup2(p[1], 1);
		pid = fork();
		if (pid == -1)
			return (perror("fork"), -1);
		if (pid == 0)
		{
			if (i == 0)
				dup2(fd, 0);
			else
				dup2(p[0], 0);
			do_child(argv[i], envp, p, fd);
		}
		else
		{
			
		}
		waitpid(pid, &status, NULL);
		i++;
	}
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
		perror("error");
	printf("executed and returning...\n");
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
