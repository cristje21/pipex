/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/16 13:34:35 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/30 11:31:15 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_array(char *s, long int n, int minus, int i)
{
	i += minus;
	s[i] = '\0';
	if (n == 0)
	{
		i--;
		s[i] = '0';
	}
	while (n > 0)
	{
		i--;
		s[i] = n % 10 + '0';
		n /= 10;
	}
	if (minus == 1)
		s[--i] = '-';
	return (s);
}

static int	m_len(long int n1)
{
	int	i;

	i = 0;
	while (n1 > 0)
	{
		n1 /= 10;
		i++;
	}
	return (i);
}

static int	check_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

char	*ft_itoa(int n)
{
	int			minus;
	long int	n1;
	char		*s;
	int			i;

	n1 = (long int)n;
	minus = check_sign(n1);
	if (minus == 1)
		n1 *= -1;
	i = m_len(n1);
	if (n1 == 0)
		i = 1;
	s = (char *)malloc(i + minus + 1);
	if (s == NULL)
		return (NULL);
	s = make_array(s, n1, minus, i);
	return (s);
}
