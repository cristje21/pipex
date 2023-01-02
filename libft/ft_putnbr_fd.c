/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 16:06:51 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/28 20:09:07 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	recursion(long int n, int fd)
{
	if (n >= 10)
		recursion(n / 10, fd);
	ft_putchar_fd(n % 10 + '0', fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	long int	x;

	x = (long int)n;
	if (x < 0)
	{
		x *= -1;
		write(fd, "-", 1);
	}
	recursion(x, fd);
}
