/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 16:43:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/02/01 09:42:04 by cristje          ###   ########.fr       */
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
	{
		ft_putnstr_fd(STDERR_FILENO, 5, "pipex: ",
			argv[1], ": ", strerror(errno), "\n");
		exit(errno);
	}
	command = get_command_acces(*argv, envp);
	if (dup2(fd, STDOUT_FILENO) != -1
		&& close(fd) != -1
		&& dup2(fd_to_read_from, STDIN_FILENO) != -1
		&& close(fd_to_read_from) != -1)
		execve(command[0], command, envp);
	perror("pipex");
	exit(errno);
}

void	do_child(char *arg, char *envp[], int fd_to_read_from, int p[])
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
	perror("pipex");
	exit(errno);
}

// void	fork_process(void)
// {
// 	pid_t	pid;

// 	pid = fork();
// 	if (pid == -1)
// 		ft_err("fork");
// 	if (pid != 0)
// 		return ;
// 	if (argc != 2)
// 		do_child(*argv, envp, )
// }

int	redirect(char *argv[], char *envp[], int argc, int fd_to_read_from)
{
	int		new_pipe[2];
	pid_t	pid;
	int		status;

	if (pipe(new_pipe) == -1)
		ft_err("pipe");
	pid = fork();
	if (pid == -1)
		ft_err("fork");
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
	if (argc > 2)
		return (redirect(argv + 1, envp, argc - 1, new_pipe[0]));
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_FAILURE);
}

void	func(void)
{
	system("leaks pipex");
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	int		status;

	if (argc < 5)
		return (ft_putnstr_fd(STDERR_FILENO, 1,
			"please enter at least 4 arguments\n"));
	if (!strncmp(argv[1], "here_doc", 8))
		here_doc(argc - 2 , &argv[2], envp);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 5, "pipex: ", argv[1], ": ", strerror(errno), "\n");
	status = redirect(&argv[2], envp, argc - 2, fd);
	atexit(&func);
	exit(status);
}
