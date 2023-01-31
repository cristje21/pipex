/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:19 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/31 17:11:15 by cvan-sch      ########   odam.nl         */
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

/*	paths	*/

char	**free_all(char	**s1);
char	**create_paths(char **envp);

/*	access	*/

char	**get_command_acces(char *command, char *envp[]);

/* prototypes */

int		redirect(char *argv[], char *envp[], int argc, int fd_to_read_from);
char	**split_arg(char *arg);
void	ft_err(char *s);

/*	pipex utils */

char	*ft_trim_quote(char *s);
void	check_status(int exit_status, char *program);
int		close_pipe(int pipe[]);
void	ft_err(char *s);
void	print_array(char **arr);

/*  here_doc    */

int	here_doc(int argc, char *argv[], char *envp[]);

#endif