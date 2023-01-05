/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/05 17:37:15 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**command;
	int		fd, i;

	fd = open(argv[1], O_RDWR);
	if (fd == -1)
	{
		printf("something went wrong opening the file\n");
		return (2);
	}
	command = get_command_acces(argv[2], envp);
	if (command == NULL)
	{
		printf("somthing went wrong\n");
		return (1);
	}
	i = 0;
	dup2(fd, 1);
	printf("%s\n", command[1]);
	//execve(command[0], command, NULL);
	//system("leaks pipex");
	// if (command == NULL)
	// 	printf("no acces!\n");
	// else
	// 	printf("acces granted!\nThis is the path of the program you are accesing: %s\n", command[0]);
	return (0);
}

/*
	first steps:
		do a command on the file given!
	check for first argument 
	make a function that splits all commands
*/