/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_atoi.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:46:58 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/08 20:47:02 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '\n' || s[i] == '\t' || s[i] == '\v'
		|| s[i] == ' ' || s[i] == '\f' || s[i] == '\r')
		i++;
	return (i);
}

int	ft_atoi(const char *str)
{
	int			i;
	int			res;
	char		*s;
	int			m;

	s = (char *)str;
	res = 0;
	i = whitespace(s);
	m = 1;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			m = -1;
		i++;
	}
	while (s[i] < 58 && s[i] > 47)
		res = res * 10 + s[i++] - '0';
	return (res * m);
}
