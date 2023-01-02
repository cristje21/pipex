/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/02 20:44:10 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	test_one_command(int argc, char *argv[], char *envp[])
{
	int 	my_pipe[2];
	int		id;
	int		fd;
	char	**command;
	
	fd = open(argv[1], O_RDONLY);
	pipe(my_pipe);
	id = fork();
	if (id != 0) // parent
	{
		close(my_pipe[0]);
		dup2(STDOUT_FILENO, my_pipe[1]);
	}
	else // child
	{
		close(fd);
		close(my_pipe[1]);
		dup2(STDIN_FILENO, my_pipe[0]);
		command = split_arg(argv[2]);
		printf("doing the command!\n%s\n", command[1]);
		
		execve("/bin/grep", command, NULL);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	test_one_command(argc, argv, envp);
	return (0);
}

/*
	first steps:
		do a command on the file given!
	check for first argument 
	make a function that splits all commands
*/