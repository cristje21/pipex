/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strmapi.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 16:07:15 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/04 04:28:43 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	char	*s1;
	size_t	i;

	len = ft_strlen(s);
	i = 0;
	s1 = (char *)malloc(len + 1 * sizeof(char));
	if (s1 == NULL)
		return (NULL);
	while (i < len)
	{
		s1[i] = f(i, s[i]);
		i++;
	}
	s1[i] = '\0';
	return (s1);
}
