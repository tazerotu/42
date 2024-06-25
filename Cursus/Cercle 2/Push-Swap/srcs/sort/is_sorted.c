/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 08:55:20 by ttas              #+#    #+#             */
/*   Updated: 2024/06/25 20:02:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted_stack(t_stack **stack_a)
{
	t_stack	*current;

	if (!stack_a || !(*stack_a)->next)
		return (FAILURE);
	current = (*stack_a)->next;
	while (current->next)
	{
		if (current->items > current->next->items)
			return (FAILURE);
		current = current->next;
	}
	return (SUCCESS);
}

int	is_sorted_str(char **str)
{
	int	i;

	i = 0;
	while (str[i] && str[i + 1])
	{
		if (ft_atoi(str[i]) > ft_atoi(str[i + 1]))
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
