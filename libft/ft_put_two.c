/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_two.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/03 13:14:10 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/26 13:17:09 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*create_string(unsigned long num, char *base, int i)
{
	char	*res;

	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	while (i > 2)
	{
		i--;
		res[i] = base[num % 16];
		num /= 16;
	}
	res[1] = 'x';
	res[0] = '0';
	return (res);
}

int	put_pointer(unsigned long num)
{
	char	*res;
	int		i;

	i = char_count(num, 16) + 2;
	res = create_string(num, "0123456789abcdef", i);
	if (!res)
		return (-1);
	i = write(1, res, ft_strlen(res));
	free(res);
	return (i);
}

int	put_unsigned(unsigned int num)
{
	int		i;
	char	*res;

	i = char_count((unsigned long)num, 10);
	res = res_set(num, "0123456789", i, 10);
	if (!res)
		return (-1);
	i = write(1, res, ft_strlen(res));
	free(res);
	return (i);
}

int	ft_putchar_return(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr_return(char *s)
{
	if (!s)
		return (write(1, "(null)", 6));
	return (write(1, s, ft_strlen(s)));
}
