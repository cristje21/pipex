/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strtrim.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 16:08:18 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/30 20:46:03 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	fetch_start_index(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, (char)s1[i]) == NULL)
			return (i);
		i++;
	}
	return (i);
}

static size_t	fetch_end_index(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0)
	{
		if (ft_strchr(set, (char)s1[i]) == NULL)
			return (i);
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*s3;

	start = fetch_start_index(s1, set);
	end = fetch_end_index(s1, set);
	if (end < start || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	s3 = (char *)malloc((end - start + 2));
	if (s3 == NULL)
		return (NULL);
	ft_strlcpy(s3, &s1[start], end - start + 2);
	return (s3);
}
