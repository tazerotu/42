/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:27:04 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:14 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

//Clears a whole double-linked list
void	ft_dblstclear(t_dblst **lst, void (*del)(void *))
{
	t_dblst	*a;
	t_dblst	*b;

	a = (*lst)->next;
	while (a)
	{
		b = a;
		a = a->next;
		del(b->content);
		free(b);
	}
	a = *lst;
	while (a)
	{
		b = a;
		a = a->prev;
		del(b->content);
		free(b);
	}
	*lst = NULL;
}

//Clears a double-linked list from the node preceding lst.
//lst becomes the new first node.
void	ft_dblstclear_before(t_dblst **lst, void (*del)(void *))
{
	t_dblst	*a;
	t_dblst	*b;

	a = (*lst)->prev;
	while (a)
	{
		b = a;
		a = a->prev;
		del(b->content);
		free(b);
	}
	(*lst)->prev = NULL;
}

//Clears a double-linked list from the node following lst.
//lst becomes the new last node.
void	ft_dblstclear_after(t_dblst **lst, void (*del)(void *))
{
	t_dblst	*a;
	t_dblst	*b;

	a = (*lst)->next;
	while (a)
	{
		b = a;
		a = a->next;
		del(b->content);
		free(b);
	}
	(*lst)->next = NULL;
}
