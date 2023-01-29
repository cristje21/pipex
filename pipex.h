/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:19 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/29 14:02:34 by cristje          ###   ########.fr       */
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

/* prototypes */

char	**split_arg(char *arg);
char	**get_command_acces(char *command, char **envp);

char	**free_all(char	**s1, char **s2);
void	ft_err(char *s);

/*	pipex utils */

char	*ft_trim_quote(char *s);
void	check_status(int exit_status, char *program);
void	close_pipe(int pipe[]);
void	ft_err(char *s);
void	print_array(char **arr);

/*  here_doc    */

int	here_doc(char *argv[], int argc);

#endif