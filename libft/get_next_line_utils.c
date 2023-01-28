/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 17:01:16 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/26 18:07:52 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#include <stdlib.h>
#include <unistd.h>

int	str_len_of_line(char *s, int check)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\n' && s[i])
		i++;
	if (check)
		return (i + 1);
	while (s[i])
		i++;
	return (i);
}

char	*new_stash(char *stash, int line_length, int check)
{
	int		size;
	char	*new_stash;
	int		i;

	i = 0;
	size = str_len_of_line(stash, 0) - line_length;
	if (size <= 0 && check)
		return (re_assign(&stash, &new_stash, 0), NULL);
	else if (size <= 0)
		return (NULL);
	new_stash = malloc(size + 1);
	if (new_stash == NULL && check)
		return (re_assign(&stash, NULL, 0), NULL);
	else if (new_stash == NULL)
		return (NULL);
	while (stash[line_length])
	{
		new_stash[i] = stash[line_length];
		i++;
		line_length++;
	}
	new_stash[i] = '\0';
	if (check)
		re_assign(&stash, NULL, 0);
	return (new_stash);
}

char	*gnl_join(char *next_line, char *stash, int line_length)
{
	char	*new;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (line_length > str_len_of_line(stash, 0))
		line_length -= 1;
	new = malloc(str_len_of_line(next_line, 0) + line_length + 1);
	if (!new)
		return (re_assign(NULL, &next_line, 1), NULL);
	if (next_line)
		while (*next_line)
			new[j++] = *(next_line++);
	next_line -= j;
	while (i < line_length)
		new[j++] = *(stash + i++);
	new[j] = '\0';
	return (re_assign(NULL, &next_line, 1), new);
}

char	*get_n_line(char *next_line, char **stash, int fd)
{
	char	buffer[BUFFER_SIZE + 1];
	int		bytes_read;
	int		line_length;

	bytes_read = BUFFER_SIZE;
	while (bytes_read == BUFFER_SIZE)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (re_assign(stash, &next_line, 2), NULL);
		buffer[bytes_read] = '\0';
		line_length = str_len_of_line(buffer, 1);
		next_line = gnl_join(next_line, buffer, line_length);
		if (next_line == NULL)
			return (NULL);
		if (line_length == bytes_read || bytes_read == 0)
			return (next_line);
		else if (line_length > bytes_read)
			continue ;
		*stash = new_stash(buffer, line_length, 0);
		if (stash == NULL)
			return (re_assign(NULL, &next_line, 1), NULL);
		return (next_line);
	}
	return (next_line);
}

int	use_stash(char **stash, char **next_line)
{
	int	len;
	int	line_length;

	if (*stash == NULL)
		return (1);
	len = str_len_of_line(*stash, 0);
	line_length = str_len_of_line(*stash, 1);
	*next_line = gnl_join(*next_line, *stash, line_length);
	if (*next_line == NULL)
		return (re_assign(stash, NULL, 0), 0);
	if (line_length >= len)
	{
		re_assign(stash, NULL, 0);
		if (line_length == len)
			return (0);
	}
	*stash = new_stash(*stash, line_length, 1);
	if (stash == NULL)
		return (re_assign(NULL, next_line, 1), 0);
	if (line_length < len)
		return (0);
	return (1);
}
