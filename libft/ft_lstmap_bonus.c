/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prambaud <prambaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 14:21:24 by prambaud          #+#    #+#             */
/*   Updated: 2024/12/11 13:00:29 by prambaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*nod;
	void	*content;

	if (!lst || !f)
		return (NULL);
	new = NULL;
	nod = NULL;
	while (lst)
	{
		content = f(lst->content);
		nod = ft_lstnew(content);
		if (nod == NULL)
		{
			del(content);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, nod);
		lst = lst->next;
	}
	return (new);
}
