/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fizzbuzz.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 10:36:46 by marvin            #+#    #+#             */
/*   Updated: 2024/06/13 09:54:09 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(void)
{
	int i = 0;
	char c;
	while (i <= 100)
	{
		if (((i % 3) == 0) && ((i % 5) == 0))
			write(1, "fizzbuzz", 8);
		else if ((i % 3) == 0)
			write(1, "fizz", 4);
		else if ((i % 5) == 0)
			write(1, "buzz", 4);
		else
		{
			c = i + '0';
			write(1, &c, 1);
		}
		write(1, "\n", 1);
	}
	return (0);
}