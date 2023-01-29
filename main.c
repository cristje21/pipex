/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/29 14:09:34 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	redirect_outfile(char *argv[], char *envp[], int fd_to_read_from)
{
	int		fd;
	char	**command;

	fd = open(argv[1], O_RDWR | O_TRUNC | O_CREAT, S_IRUSR
			| S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
	if (fd == -1)
		exit(errno);
	command = get_command_acces(*argv, envp);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	dup2(fd_to_read_from, STDIN_FILENO);
	close(fd_to_read_from);
	if (execve(command[0], command, NULL) == -1)
		exit(errno);
}

void	do_child(char *arg, char *envp[], int fd_to_read_from, int p[])
{
	char	**command;

	if (fd_to_read_from == -1)
		exit(ENOENT);
	command = get_command_acces(arg, envp);
	dup2(fd_to_read_from, STDIN_FILENO);
	close(fd_to_read_from);
	dup2(p[1], STDOUT_FILENO);
	close_pipe(p);
	if (execve(command[0], command, NULL) == -1)
		exit(errno);
}

int	redirect(char *argv[], char *envp[], int argc, int fd_to_read_from)
{
	int		new_pipe[2];
	pid_t	pid;
	int		status;

	if (pipe(new_pipe) == -1)
		ft_err("pipex: pipe");
	pid = fork();
	if (pid == -1)
		ft_err("pipex: fork");
	if (pid == 0)
	{
		if (argc != 2)
			do_child(*argv, envp, fd_to_read_from, new_pipe);
		close_pipe(new_pipe);
		redirect_outfile(argv, envp, fd_to_read_from);
	}
	if (argc == 2)
		close(new_pipe[0]);
	close(new_pipe[1]);
	wait(&status);
	check_status(status, *argv);
	if (argc > 2)
		redirect(argv + 1, envp, argc - 1, new_pipe[0]);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (300);
}

int	main(int argc, char *argv[], char *envp[])
{
	int	fd;

	if (argc != 5)
	{
		ft_putstr_fd("error: enter 4 arguments\n", STDERR_FILENO);
		exit(1);
	}
	if (!strncmp(argv[1], "here_doc", 9))
		return(here_doc(&argv[2], argc - 2));
	fd = open(argv[1], O_RDONLY);
	return (redirect(&argv[2], envp, argc - 2, fd));
}
