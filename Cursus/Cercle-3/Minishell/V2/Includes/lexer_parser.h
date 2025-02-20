/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_parser.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 12:04:47 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/20 18:25:30 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PARSER_H
# define LEXER_PARSER_H

# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

enum e_token_quote_type
{
	Q_WITHOUT,
	Q_SIMPLE,
	Q_DOUBLE
};

typedef struct s_command
{
	char				**redir_tok;
	char				**arg_tok;
	struct s_command	*prev;
	struct s_command	*next;
}	t_cmd;

typedef struct s_quote_checker
{
	int	s_count;
	int	d_count;
	int	last_s;
	int	last_d;
}	t_quote;

typedef struct s_token_lst
{
	char	*str;
	int		quote_type;
}	t_tok;

int		check_incorrect_quotes(char *input);
char	*process_line(char *input);
t_list	**ft_tokenize_1(char *input);
void	del_token_1(void *tok);
char	*ft_trim_token(char *src);

#endif