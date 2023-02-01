/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   split_arg_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: cristje <cristje@student.42.fr>              +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/01/02 16:19:12 by cvan-sch      #+#    #+#                 */
/*   Updated: 2023/02/01 15:06:54 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
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

static int	check_quotes(char *s)
{
	int	len;

	len = ft_strlen(s);
	if (len > 1)
		if (s[0] == '\'' || s[0] == '\"')
			if (s[len - 1] == s[0])
				return (1);
	return (0);
}

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
			ft_err("malloc: ");
		if (check_quotes(result[k]))
		{
			temp = ft_trim_quote(result[k]);
			result[k] = temp;
		}
		i += j + 1;
		k += 1;
	}
	result[k] = NULL;
	return (result);
}

char	**split_arg(char *arg)
{
	char	**result;
	int		count;

	count = count_args(arg);
	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		ft_err("malloc: ");
	result = make_all(result, arg, count);
	return (result);
}
