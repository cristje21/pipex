/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/12/30 16:43:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/30 22:08:04 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

void	redirect_outfile(char *argv[], char **paths, int fd_to_read_from)
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
	command = get_command_acces(*argv, paths);
	if (dup2(fd, STDOUT_FILENO) != -1 && close(fd) != -1
		&& dup2(fd_to_read_from, STDIN_FILENO) != -1
		&& close(fd_to_read_from) != -1)
		execve(command[0], command, NULL);
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ", strerror(errno), "\n");
	exit(errno);
}

void	do_child(char *arg, char **paths, int fd_to_read_from, int p[])
{
	char	**command;

	if (fd_to_read_from == -1)
		exit(ENOENT);
	command = get_command_acces(arg, paths);
	if (dup2(fd_to_read_from, STDIN_FILENO) != -1
		&& close(fd_to_read_from) != -1
		&& dup2(p[1], STDOUT_FILENO) != -1
		&& close_pipe(p))
		if (execve(command[0], command, NULL) == -1)
			;
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ", strerror(errno), "\n");
	exit(errno);
}

void	redirect(char *argv[], char **paths, int argc, int fd_to_read_from)
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
			do_child(*argv, paths, fd_to_read_from, new_pipe);
		close_pipe(new_pipe);
		redirect_outfile(argv, paths, fd_to_read_from);
	}
	if (argc == 2)
		close(new_pipe[0]);
	close(new_pipe[1]);
	wait(&status);
	if (argc > 2)
		return (redirect(argv + 1, paths, argc - 1, new_pipe[0]));
	if (WIFEXITED(status))
	{
		//printf("terminated normally with status %d\n", WEXITSTATUS(status));
		exit(WEXITSTATUS(status));
	}
	exit(EXIT_FAILURE);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		fd;
	char	**paths;

	if (argc < 5)
		return (ft_putnstr_fd(STDERR_FILENO, 1,
			"please enter at least 4 arguments\n"));
	paths = create_paths(envp);
	if (paths == NULL)
		return (ENOMEM);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putnstr_fd(STDERR_FILENO, 5, "pipex: ", argv[1], ": ", strerror(errno), "\n");
	redirect(&argv[2], paths, argc - 2, fd);
	exit(EXIT_FAILURE);
}
