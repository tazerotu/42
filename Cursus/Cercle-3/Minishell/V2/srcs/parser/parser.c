/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:29:17 by clai-ton          #+#    #+#             */
/*   Updated: 2025/01/23 13:01:53 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

t_list	*parse_line(char *input)
{
	t_list	*cmds;
	char	*processed_input;

	processed_input = process_line(input);
	return (NULL);
}