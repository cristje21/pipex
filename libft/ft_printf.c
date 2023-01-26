/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 21:15:52 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/26 13:16:48 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_all(va_list list, const char c)
{
	int	count;

	count = -1;
	if (c == 'c')
		count = ft_putchar_return(va_arg(list, int));
	else if (c == 's')
		count = ft_putstr_return(va_arg(list, char *));
	else if (c == '%')
		return (write(1, "%", 1));
	else if (c == 'x' || c == 'X')
		count = put_base_16(va_arg(list, unsigned int), c);
	else if (c == 'd' || c == 'i')
		count = put_d(va_arg(list, int));
	else if (c == 'p')
		count = put_pointer(va_arg(list, unsigned long));
	else if (c == 'u')
		count = put_unsigned(va_arg(list, unsigned int));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	list;
	int		write_return;
	int		count;

	va_start(list, str);
	count = 0;
	while (*str)
	{
		while (*str != '%' && *str)
		{
			write_return = write(1, str++, 1);
			if (write_return == -1)
				return (-1);
			count += write_return;
		}
		if (*str == '\0')
			break ;
		write_return = write_all(list, *(str + 1));
		if (write_return == -1)
			return (-1);
		count += write_return;
		str += 2;
	}
	va_end(list);
	return (count);
}
