/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:47 by clai-ton          #+#    #+#             */
/*   Updated: 2025/01/23 14:55:35 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

typedef struct s_command
{
	char	**redir_tok;
	char	**arg_tok;
}	t_cmd;

typedef struct s_quote_checker
{
	int	s_count;
	int	d_count;
	int	last_s;
	int	last_d;
}	t_quote;

int		check_incorrect_quotes(char *input);
char	*process_line(char *input);

t_list	*parse_line(char *input);

#endif