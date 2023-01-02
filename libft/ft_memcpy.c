/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memcpy.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:32:51 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/28 15:34:34 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*sorc;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 0;
	dest = (unsigned char *)dst;
	sorc = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = sorc[i];
		i++;
	}
	return (dst);
}
