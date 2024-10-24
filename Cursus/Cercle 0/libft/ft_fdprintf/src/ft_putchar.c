/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 12:45:10 by ttas              #+#    #+#             */
/*   Updated: 2024/10/24 09:18:48 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_fdprintf.h"

int	ft_putchar_fd(int fd, char c)
{
	write(fd, &c, 1);
	return (1);
}
