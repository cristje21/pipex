/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:24:36 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/26 13:17:15 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	char_count(unsigned long num, int base)
{
	int	count;

	count = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}

char	*res_set(unsigned int num, char *base_set, int i, int base)
{
	char	*res;

	res = malloc(i + 1);
	if (res == NULL)
		return (NULL);
	res[i] = '\0';
	while (i > 0)
	{
		i--;
		res[i] = base_set[num % base];
		num /= base;
	}
	return (res);
}

int	put_base_16(unsigned int num, const char c)
{
	int		i;
	char	*res;

	i = char_count(num, 16);
	if (i == 0)
		i = 1;
	if (c == 'x')
		res = res_set(num, "0123456789abcdef", i, 16);
	else
		res = res_set(num, "0123456789ABCDEF", i, 16);
	if (!res)
		return (-1);
	i = write(1, res, ft_strlen(res));
	free(res);
	return (i);
}

int	put_d(int num)
{
	char	*res;

	res = ft_itoa(num);
	if (!res)
		return (-1);
	num = write(1, res, ft_strlen(res));
	free(res);
	return (num);
}
