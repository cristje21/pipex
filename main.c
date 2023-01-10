/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/10 18:01:47 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_validity(int argc, char *argv[], char *envp[])
{
	if (argc < 5 || argv == NULL || envp == NULL)
		return(1);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	char	**command;
	int		fd;

	if (check_validity(argc, argv, envp))
	{
		printf("need atleast 4 arguments to show of the magic!\n");
		return (1);
	}
	if ((fd = open(argv[1], O_RDONLY) == -1))
	{
		printf("files doesn't exist.\n");
		return (2);
	}
	dup2(fd, 0);
	close(fd);
	command = get_command_acces(argv[2], envp);
	if (!command)
	{
		perror("check the executable.\n");
		return (0);
	}
	//printf("%s\n", argv[1]);
	execve(command[0], command, NULL);
	// fork();
	// while ((id = wait(NULL)) != -1)
	// 	printf("%d\n", id);
	// if (id == -1)
	// 	printf("id: %d\n", id);
}

/*
	open the first file
	do the command with that as input
	then go in a loop and make the output of the command the writing end of the file
*/
