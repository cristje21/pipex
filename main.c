/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/03 20:08:41 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **command, char **argv, char **envp)
{
	int		check;
	char	**paths;
	char	*s;
	int		i;

	check = 0;
	i - 0;
	command = split_arg(argv[1]);
	while (paths[i])
	{
		s = ft_strjoin(paths[i], command[0]);
		if (s == NULL)
			return (NULL);
		if (!access(s, X_OK | F_OK))
			return (s);
		free(s);
		i++;
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		input;
	char	**command;
	char	*path;
	char	**paths;

	paths = ft_split(envp[6][5], ':');
	if (argc != 3)
		return (0);
	if ((input = open(argv[1], O_RDONLY)) == -1)
		return (1);
	path = get_path(command, argv, envp);
	return (0);
}

/*
	first steps:
		do a command on the file given!
	check for first argument 
	make a function that splits all commands
*/