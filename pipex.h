/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:19 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/08 12:54:09 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libraries included */

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <string.h>

# include "libft/libft.h"

/* prototypes */

char	**split_arg(char *arg);
char	**get_command_acces(char *command, char **envp);

char	**free_all(char	**s1, char **s2);

#endif