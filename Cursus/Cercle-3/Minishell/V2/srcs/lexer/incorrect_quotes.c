/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect_quotes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:25:59 by clai-ton          #+#    #+#             */
/*   Updated: 2025/01/23 14:56:47 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

static t_quote	*quote_init(void)
{
	t_quote	*quote;

	quote = malloc(sizeof(t_quote));
	quote->last_s = -1;
	quote->last_d = -1;
	quote->s_count = 0;
	quote->d_count = 0;
	return (quote);
}

static int	check_simple(t_quote *quote, int i)
{
	quote->s_count++;
	if (quote->s_count % 2 == 0
		&& quote->last_s < quote->last_d
		&& quote->d_count % 2 != 0)
		return (1);
	quote->last_s = i;
	return (0);
}

static int	check_double(t_quote *quote, int i)
{
	quote->d_count++;
	if (quote->d_count % 2 == 0
		&& quote->last_d < quote->last_s
		&& quote->s_count % 2 != 0)
		return (1);
	quote->last_d = i;
	return (0);
}
/*
** Returns 1 if quotes are incorrect, 0 otherwise.
** Incorrect includes quotes opening but not ending,
** and when a type of quotes between simple and double
** opens after the other type opened
** but also ends after the other type closed.
*/
int	check_incorrect_quotes(char *input)
{
	t_quote	*quote;
	int		i;
	int		ret_val;

	quote = quote_init();
	i = 0;
	ret_val = 0;
	while (input[i])
	{
		if (input[i] == '\'')
			ret_val |= check_simple(quote, i);
		else if (input[i] == '"')
			ret_val |= check_double(quote, i);
		if (ret_val)
			break;
		++i;
	}
	ret_val |= quote->s_count % 2 != 0;
	ret_val |= quote->d_count % 2 != 0;
	free(quote);
	return (ret_val);
}
