/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:19 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/02/02 15:36:02 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

/* libraries included */

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# include <stdio.h>
# include <sys/wait.h>
# include <sys/errno.h>
# include <string.h>

/*	paths	*/

char	**create_paths(char **envp);

/*	access	*/

char	**get_command_acces(char *command, char *envp[]);

/* prototypes main	*/

int		redirect(char *argv[], char *envp[], int argc, int fd_to_read_from);
char	**split_arg(char *arg);

/*	pipex utils */

char	*ft_trim_quote(char *s);
int		close_pipe(int pipe[]);
int		pipe_and_fork(int p[]);

/*	error	*/

void	ft_err(char *s);
char	**free_all(char	**s1);
void	initial_error(int argc);

#endif