/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_bonus.h                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:19 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/02/06 19:15:02 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

/* libraries included */

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <sys/errno.h>

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

/*  here_doc    */

int		here_doc(int argc, char *argv[], char *envp[]);

/*	error	*/

void	ft_err(char *s);
char	**free_all(char	**s1);
void	initial_error(int argc, char *argv[]);

#endif