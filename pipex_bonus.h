/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:19 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/01 16:29:06 by cristje          ###   ########.fr       */
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
int		close_pipe(int pipe[]);
void	ft_err(char *s);
void	print_array(char **arr);
int		pipe_and_fork(int p[]);

/*  here_doc    */

int		here_doc(int argc, char *argv[], char *envp[]);

#endif