/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memset.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:34:24 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/08 20:34:26 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*b1;

	b1 = (unsigned char *)b;
	i = 0;
	while (i < len)
		b1[i++] = (unsigned char)c;
	return (b);
}
