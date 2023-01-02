/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memmove.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:32:24 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/28 14:37:39 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dest;
	unsigned char	*sorc;
	int				lenght;

	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	if (dest > sorc)
	{
		lenght = len - 1;
		while (lenght >= 0)
		{
			dest[lenght] = sorc[lenght];
			lenght--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
