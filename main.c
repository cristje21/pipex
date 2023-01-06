/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/06 18:39:25 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	char	**command;
	int		fd, i;

	fd = open(argv[1], O_RDONLY);
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
	dup2(fd, 0);
	//printf("%s\n%s\n%s\n", command[0], command[1], command[2]);
	execve(command[0], command, NULL);
	return (0);
}

/*
	first steps:
		do a command on the file given!
	check for first argument 
	make a function that splits all commands
*/