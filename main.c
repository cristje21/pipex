/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/13 20:12:02 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

int	execute(int argc, char *argv[], char *envp[])
{
	int		pid;
	int		a_pipe[2];
	char	**command;
	int		fd;

	if (pipe(a_pipe) == -1)
		return (-1);
	dup2(a_pipe[0], 0);
	dup2(a_pipe[1], 1);
	while (argc > 1)
	{
		if ((pid = fork()) == -1)
			return (-1);
		if (pid == 0)
		{
			close(a_pipe[1]);
			command = get_command_acces(*argv, envp);
			if (command == NULL)
				return (-1);
			execve(command[0], command, NULL);
			return (-1);
		}
		else
			break ;
	}
	wait(NULL);
	return (0);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd;

	if (argc < 3)
	{
		printf("%d arguments is too little.\n", argc - 1);
		return (0);
	}
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		return (perror("error"), errno);
	dup2(fd, 0);
	close(fd);
	if (execute(argc - 2, &argv[2], envp) == -1)
		perror("something went wrong");
	printf("returning...\n");
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
