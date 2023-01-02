/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_memchr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/08 20:46:30 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/08 20:46:32 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	c1;

	i = 0;
	s1 = (unsigned char *)s;
	c1 = (unsigned char)c;
	while (i < n)
	{
		if (s1[i] == c1)
			return (&s1[i]);
		i++;
	}
	return (0);
}
