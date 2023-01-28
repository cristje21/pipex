/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:19 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/28 10:20:27 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libraries included */

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

/* prototypes */

char	**split_arg(char *arg);
char	**get_command_acces(char *command, char **envp);

char	**free_all(char	**s1, char **s2);
void	error(char *s, int err);

#endif