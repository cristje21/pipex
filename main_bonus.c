/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/02 10:26:42 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include "libft/libft.h"

static void	do_last(char *argv[], char *envp[], int fd_to_read_from)
{
	int		fd;
	char	**command;

	if (append(argv))
		fd = open(argv[1], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	else
		fd = open(argv[1], O_WRONLY | O_APPEND | O_CREAT, 0644);
	if (fd == -1)
	{
		ft_putstr_fd("pipex: ", STDERR_FILENO);
		perror(argv[1]);
		exit(errno);
	}
	command = get_command_acces(*argv, envp);
	if (dup2(fd, STDOUT_FILENO) != -1
		&& close(fd) != -1
		&& dup2(fd_to_read_from, STDIN_FILENO) != -1
		&& close(fd_to_read_from) != -1)
		execve(command[0], command, envp);
	perror("pipex: child execution");
	exit(errno);
}

static void	do_child(char *arg, char *envp[], int fd_to_read_from, int p[])
{
	char	**command;

	if (fd_to_read_from == -1)
		exit(ENOENT);
	command = get_command_acces(arg, envp);
	if (dup2(fd_to_read_from, STDIN_FILENO) != -1
		&& close(fd_to_read_from) != -1
		&& dup2(p[1], STDOUT_FILENO) != -1
		&& close_pipe(p))
		execve(command[0], command, envp);
	perror("pipex: child execution");
	exit(errno);
}

int	redirect(char *argv[], char *envp[], int argc, int fd_to_read_from)
{
	int		new_pipe[2];
	pid_t	pid;
	int		status;

	pid = pipe_and_fork(new_pipe);
	if (pid == 0)
	{
		if (argc != 2)
			do_child(*argv, envp, fd_to_read_from, new_pipe);
		close_pipe(new_pipe);
		do_last(argv, envp, fd_to_read_from);
	}
	if (argc == 2)
		close(new_pipe[0]);
	close(new_pipe[1]);
	if (argc > 2)
		return (redirect(argv + 1, envp, argc - 1, new_pipe[0]));
	if (waitpid(pid, &status, 0) == -1)
		perror("pipex: waitpid()");
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		status;

	int i = unlink("kassbaas");
	if (argc < 6 || ft_strncmp(*argv, "./pipex", 7))
	{
		if (argc < 5)
			return (ft_putstr_fd("please enter at least 4 arguments\n",
					STDERR_FILENO), 1);
		else if (argc == 5 && ft_strncmp(*(argv + 1), "here_doc", 8))
		{
			ft_putstr_fd("format: './pipex [infile] [cmd1]    [cmd2] [...]  [outfile]'\n", STDERR_FILENO);
			ft_putstr_fd("format: './pipex here_doc [limiter] [cmd1] [cmd2] [...] [outfile]'\n", STDERR_FILENO);
			return (1);
		}
	}
	if (!strncmp(argv[1], "here_doc", 8))
		here_doc(argc - 2, &argv[2], envp);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 5, "pipex: ", argv[1], ": ",
			strerror(errno), "\n");
	status = redirect(&argv[2], envp, argc - 2, fd);
	exit(status);
}
