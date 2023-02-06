/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 14:44:56 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/04 15:15:46 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

void	ft_err(char *s)
{
	ft_putstr_fd("pipex: ", STDERR_FILENO);
	perror(s);
	exit(errno);
}

char	**free_all(char	**s1)
{
	int	i;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i])
	{
		free(s1[i]);
		i++;
	}
	free(s1);
	return (NULL);
}

void	initial_error(int argc, char *argv[])
{
	if (argc < 6)
	{
		if (argc < 5)
		{
			ft_putnstr_fd(STDERR_FILENO, 2, "format: ./pipex [infile] [cmd1]",
				" [cmd2] [...] [outfile]\n");
			exit(EXIT_FAILURE);
		}
		else if (argc == 5 && !ft_strncmp(*(argv + 1), "here_doc", 8))
		{
			ft_putnstr_fd(STDERR_FILENO, 2, "format: ./pipex here_doc [infile]",
				" [cmd1] [cmd2] [...] [outfile]\n");
			exit(EXIT_FAILURE);
		}
	}
	return ;
}
