/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/23 20:28:00 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	error_checking(char *s)
{
	perror(s);
	exit(1);
}

void	do_child(char *arg, char *envp[], int fd_to_read_from, int p[])
{
	char	**command;

	if (fd_to_read_from == -1)
		exit(errno);
	command = get_command_acces(arg, envp);
	if (command == NULL)
	{
		// command not found/ prob best to exit in other function if malloc fails
		printf("no Command Acces!\n");
		exit (43);
	}
	dup2(fd_to_read_from, 0);
	close(fd_to_read_from);
	dup2(p[1], 1);
	close(p[1]);
	close(p[0]);
	execve(command[0], command, NULL);
	printf("execve did not execute properly!\n");
	exit(98);
}

// void	redirect_outfile(int p[], char *file)
// {
// 	int	fd;

// 	fd = open(file, O_WRONLY | O_TRUNC | O_CREAT);
// 	if (fd == -1)
// 	{
// 		printf("something went wrong creating or opening the outfile!\n");
// 		exit(errno);
// 	}
// 	dup2(fd, p[1])
// }

int	recursive_redirection(char *argv[], char *envp[], int argc, int fd_to_read_from)
{
	int		new_pipe[2];
	pid_t	pid;
	char	**command;

	if (pipe(new_pipe) == -1)
		error_checking("pipe");
	pid = fork();
	if (pid == -1)
		error_checking("fork");
	if (pid == 0)
	{
		if (argc == 1)
			dup2(1, new_pipe[1]);
		do_child(*argv, envp, fd_to_read_from, new_pipe);
		//do child execute command
	}
	close(new_pipe[1]);
	wait(NULL);
	if (argc != 1)
		return (recursive_redirection(++argv, envp, --argc, new_pipe[0]));
	printf("done with all commands and returning!\n");
	return 0;
}

void	initialize(int argc, char *argv[], char *envp[])
{
	int		fd;

	fd = open(*argv, O_RDONLY);
	if (fd == -1)
		perror(*argv);
	recursive_redirection(++argv, envp, argc - 1, fd);
}

int	main(int argc, char *argv[], char *envp[])
{
	if (argc < 1)
	{
		printf("%d arguments is too little.\n", argc - 1);
		return (0);
	}
	initialize(argc - 1, &argv[1], envp);
	return (0);
	printf("%d\n", errno);
	printf("main process done with it's execution!\n");
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
