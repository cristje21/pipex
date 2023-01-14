/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cristje <cristje@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:19:12 by cvan-sch          #+#    #+#             */
/*   Updated: 2023/01/13 19:10:56 by cristje          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"

static int	count_word_len(char *arg, int i)
{
	int	j;

	j = 0;
	if (arg[i] == '\'' || arg[i] == '\"')
	{
		j++;
		while (arg[i + j] != arg[i] && arg[i + j])
			j++;
		if (!arg[i + j])
			j = 0;
	}
	while (arg[i + j] != ' ' && arg[i + j])
			j++;
	return (j);
}

//check == 0 if i just need plain count
//check == 1 if 

static int	count_args(char *arg)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (arg[i])
	{
		while (arg[i] == ' ')
			i++;
		if (arg[i])
			count++;
		i += count_word_len(arg, i);
	}
	return (count);
}

static char	**free_all_malloc_failure(char **result, int i)
{
	i--;
	while (i >= 0)
	{
		free(result[i]);
		i--;
	}
	free(result);
	return (NULL);
}

//if ((result[k][0] == '\'' && result[k][ft_strlen(result[k]) -1] == '\'') || result[k][0] == '\"')

static char	**make_all(char **result, char *arg, int count)
{
	int		i;
	int		j;
	int		k;
	char	*temp;

	i = 0;
	k = 0;
	while (k < count)
	{
		while (arg[i] == ' ')
			i++;
		j = count_word_len(arg, i);
		result[k] = ft_substr(arg, i, j);
		if (result[k] == NULL)
			return (free_all_malloc_failure(result, k));
		if ((result[k][0] == '\'' && result[k][ft_strlen(result[k]) - 1] == '\'' && ft_strlen(result[k]) > 1)
		|| (result[k][0] == '\"' && result[k][ft_strlen(result[k]) - 1] == '\"' && ft_strlen(result[k]) > 1))
		{
			temp = ft_strtrim(result[k], "'\"");
			free(result[k]);
			result[k] = temp;
		}
		i += j + 1;
		k++;
	}
	result[k] = NULL;
	return (result);
}

char	**split_arg(char *arg)
{
	char	**result;
	int		check;
	int		count;

	count = count_args(arg);
	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	result = make_all(result, arg, count);
	if (result == NULL)
		return (NULL);
	return (result);
}
