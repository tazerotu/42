/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 12:37:29 by ttas              #+#    #+#             */
/*   Updated: 2024/10/15 08:44:38 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Pipex.h"

void	*ft_memcpy(void *dest, void *src, size_t n)
{
	char	*csrc;
	char	*cdest;
	size_t	i;

	csrc = (char *)src;
	cdest = (char *)dest;
	i = 0;
	if (csrc < cdest && csrc + n > cdest)
	{
		ft_memmove(cdest, csrc, n);
	}
	else
	{
		while (i < n)
		{
			cdest[i] = csrc[i];
			i++;
		}
	}
	return (cdest);
}

// i = n;
// while (i > 0)
// {
// 	cdest[i - 1] = csrc[i - 1];
// 	i--;
// }