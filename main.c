/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/08 21:42:31 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	int id;

	fork();
	while ((id = wait(NULL)) != -1)
		printf("%d\n", id);
	if (id == -1)
		printf("id: %d\n", id);
}

/*
	open the first file
	do the command with that as input
	then go in a loop and make the output of the command the writing end of the file
*/
