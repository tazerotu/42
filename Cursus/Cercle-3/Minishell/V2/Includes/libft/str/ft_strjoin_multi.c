/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_multi.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:24:39 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/28 18:15:26 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int	ft_get_malloc_size(int strs_size, char **strs, char *sep)
{
	int	i;
	int	malloc_size;
printf("entering ft_get_malloc_size\n");
	if (!sep || !sep[0])
		malloc_size = 0;
	else
		malloc_size = ft_strlen(sep) * (strs_size - 1);
printf("gone past checking sep\n");
	i = 0;
	while (i < strs_size && strs[i])
	{
printf("i = %i, %s\n", i, strs[i]);
		malloc_size += ft_strlen(strs[i++]);
	}
	return (malloc_size);
}

static char	*ft_strcat_join(char *dest, char *src, int *dest_idx)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[*dest_idx] = src[i];
		++i;
		(*dest_idx)++;
	}
	return (dest);
}

static void	ft_my_join(int size, char **strs, char *sep, char *dest)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < size && strs[i])
	{
		ft_strcat_join(dest, strs[i], &j);
		if (i < size - 1)
		{
			ft_strcat_join(dest, sep, &j);
		}
		++i;
	}
	dest[j] = '\0';
}

/*
** Joins the strs_size first strings of strs,
** adding the string sep in-between.
** sep can be empty or NULL.
** The join will stop at the first NULL string,
** even if it is of a smaller index than strs_size - 1.
*/
char	*ft_strjoin_multi(int strs_size, char **strs, char *sep)
{
	int		malloc_size;
	char	*dest;
printf("entering ft_strjoin_multi\n");
	if (strs_size == 0)
	{
		dest = (char *) malloc(sizeof(char));
		dest[0] = '\0';
		return (dest);
	}
	malloc_size = ft_get_malloc_size(strs_size, strs, sep);
	dest = (char *) malloc(sizeof(char) * malloc_size);
	if (dest == NULL)
		return (NULL);
	ft_my_join(strs_size, strs, sep, dest);
	return (dest);
}
