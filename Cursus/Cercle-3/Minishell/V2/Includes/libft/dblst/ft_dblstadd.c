/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblstadd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:06:26 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/20 18:27:11 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
** Adds one node at the first position of the double-linked list lst
*/
void	ft_dblstadd_front(t_dblst **lst, t_dblst *new)
{
	t_dblst	*next;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	next = ft_dblstfirst(*lst);
	next->prev = new;
	new->next = next;
}

/*
** Adds one node at the last position of the double-linked list lst
*/
void	ft_dblstadd_back(t_dblst **lst, t_dblst *new)
{
	t_dblst	*prev;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	prev = ft_dblstlast(*lst);
	prev->next = new;
	new->prev = prev;
}
