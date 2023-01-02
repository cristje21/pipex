/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strjoin.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 11:55:16 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/13 11:55:19 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (s == 0)
		return (0);
	while (ft_strlen(s1) > i)
	{
		s[i] = s1[i];
		i++;
	}
	while ((ft_strlen(s1) + ft_strlen(s2)) > i)
		s[i++] = s2[j++];
	s[i] = '\0';
	return (s);
}
