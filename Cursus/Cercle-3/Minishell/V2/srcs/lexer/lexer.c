/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:07:03 by clai-ton          #+#    #+#             */
/*   Updated: 2025/01/23 21:14:48 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

t_list *ft_tokenize(char *input)
{
	int		i;
	int		j;
	int		quote_type;
	t_tok	*tok;

	i = 0;
	quote_type = Q_WITHOUT;
	while (input[i])
	{
		//todo
		++i;
	}
	return (NULL);//todo replace
}

char	*replace_var(char *input)
{
	
}

char	*process_line(char *input)
{
	if (check_incorrect_quotes(input))
		return (NULL);
	
	return (NULL);
}
