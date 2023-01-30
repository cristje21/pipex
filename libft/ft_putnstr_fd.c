/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnstr_fd.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/30 16:02:25 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/01/30 16:28:34 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnstr_fd(int fd, int n, ...)
{
	va_list	lst;
	int		count;
	int		write_return;
	char	*s;

	count = 0;
	va_start(lst, n);
	while (n > 0)
	{
		s = va_arg(lst, char *);
		if (s == NULL)
			write_return = write(fd, "(null)", 6);
		else
			write_return = write(fd, s, ft_strlen(s));
		if (write_return == -1)
			return (va_end(lst), -1);
		count += write_return;
		n--;
	}
	va_end(lst);
	return (count);
}
