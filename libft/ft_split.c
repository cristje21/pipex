/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/28 15:15:15 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/30 11:29:31 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**malloc_prot(char **result, size_t j)
{
	size_t	i;

	i = 0;
	while (i < j)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

static char	**make_all(char **result, char const *s, char c, size_t array_count)
{
	char const	*temporary;
	size_t		len;
	size_t		i;

	i = 0;
	while (i < array_count)
	{
		len = 0;
		while (*s == c && *s)
			s++;
		temporary = s;
		while (*s != c && *s)
		{
			s++;
			len++;
		}
		result[i] = ft_substr(temporary, 0, len);
		if (!result[i++])
			return (malloc_prot(result, i));
	}
	result[i] = NULL;
	return (result);
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s != c && *s)
			i++;
		while (*s != c && *s)
			s++;
	}
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	size_t	array_count;

	array_count = count_words(s, c);
	result = (char **)malloc((array_count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = make_all(result, s, c, array_count);
	return (result);
}
