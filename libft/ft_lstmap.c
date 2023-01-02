/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: cvan-sch <cvan-sch@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/27 10:58:13 by cvan-sch      #+#    #+#                 */
/*   Updated: 2022/11/10 14:10:41 by cvan-sch      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*duplicate;
	t_list	*new_node;

	duplicate = NULL;
	while (lst)
	{
		new_node = ft_lstnew(f(lst->content));
		if (new_node == NULL)
		{
			ft_lstclear(&duplicate, del);
			return (NULL);
		}
		ft_lstadd_back(&duplicate, new_node);
		lst = lst->next;
	}
	return (duplicate);
}
