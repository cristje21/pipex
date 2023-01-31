/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   pipex_utils.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/28 20:18:41 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/31 15:14:21 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"

char	*ft_trim_quote(char *s)
{
	int		len;
	char	*new;

	len = ft_strlen(s);
	new = malloc(len - 1);
	if (new == NULL)
		exit(ENOMEM);
	ft_strlcpy(new, s + 1, len - 1);
	free(s);
	return (new);
}

int	close_pipe(int p[])
{
	if (close(p[0]) != -1 && close(p[1]) != -1)
		return (1);
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ", strerror(errno), "\n");
	exit(errno);
}

void	ft_err(char *s)
{
	ft_putnstr_fd(STDERR_FILENO, 3, "pipex: ", s, strerror(errno));
	exit(errno);
}
