/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstclear.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 09:58:49 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/10/27 10:34:59 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	while (*lst != NULL)
	{
		t = *lst;
		(*del)(t->content);
		*lst = t->next;
		free(t);
	}
	lst = NULL;
}
