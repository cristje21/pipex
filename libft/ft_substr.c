/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_substr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/13 08:29:47 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/27 15:50:37 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	str_len_s;

	str_len_s = ft_strlen(s);
	if (start >= str_len_s)
		return (ft_strdup(""));
	if ((str_len_s - start) < len)
		len = str_len_s - start;
	sub = malloc(len + 1);
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], len + 1);
	return (sub);
}
