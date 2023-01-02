/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strdup.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/12 17:18:52 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/03 21:20:58 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;

	str = (char *)malloc(ft_strlen(s1) + 1 * sizeof(char));
	if (str == 0)
		return (0);
	ft_strlcpy(str, s1, (ft_strlen(s1) + 1) * sizeof(char));
	return (str);
}
