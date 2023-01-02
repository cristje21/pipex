/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlcat.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:37:18 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/28 10:47:03 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s;
	size_t	d;

	s = ft_strlen(src);
	d = ft_strlen(dst);
	i = 0;
	if (d >= dstsize)
		return (dstsize + s);
	while ((d + i < dstsize - 1) && src[i])
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (s + d);
}
