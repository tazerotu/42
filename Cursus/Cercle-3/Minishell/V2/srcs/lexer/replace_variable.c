/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_variable.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 16:35:19 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/28 18:21:37 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/lexer_parser.h"

static char	*replace_var_helper(int sub_start, int *i, char *str)
{
	char	*var;
	char	*value;
printf("entering replace_var_helper\n");
	++(*i);
	while (str[*i] && (ft_isalnum(str[*i]) || str[*i] == '_'))
		++(*i);
	var = ft_substr(str, sub_start, *i - 1 - sub_start);
	value = getenv(var);
	free(var);
	return (value);
}

static int	fill_split(char **split_str, char *str)
{
	int		i;
	int		sub_start;
	int		j;
printf("entering fill split\n");
	i = -1;
	sub_start = 0;
	j = 0;
	while (str[++i])
	{
		if (str[i] == '$' && ft_isalpha(str[i + 1]))
		{
			if (i != sub_start)
				split_str[j++] = ft_substr(str, sub_start, i - 1 - sub_start);
			sub_start = i + 1;
			split_str[j] = replace_var_helper(sub_start, &i, str);
			if (split_str[j])
				++j;
			if (!str[i])
				return (j);
			sub_start = i;
			--i;
		}
	}
	split_str[j] = ft_substr(str, sub_start, i - 1 - sub_start);
	return (j);
}

static int	count_split_token(char *str)
{
	int		i;
	int		count;
printf("entering count split token\n");
	i = 0;
	if (str[i] == '$' && ft_isalpha(str[i + 1]))
		count = 0;
	else
		count = 1;
	while (str[i])
	{
		if (str[i] == '$' && ft_isalpha(str[i + 1]))
		{
			++count;
			++i;
			while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
				++i;
			if (str[i] && str[i] != '$')
				++count;
			continue;
		}
		++i;
	}
printf("split count = %i\n", count);
	return (count);
}

static void	free_split_str(char **split_str)
{
	int	i;
printf("entering free split str\n");
	i = -1;
	while (split_str[++i])
		free(split_str[i]);
	free(split_str);
}

void	replace_var(t_list	**tok_lst)
{
	t_list	*cur_lst;
	t_tok	*tok;
	int		count;
	char	**split_str;
printf("entering replace_var\n");
	cur_lst = *tok_lst;
	while (cur_lst)
	{
		tok = (t_tok *) cur_lst->content;
		if (tok->quote_type == Q_WITHOUT || tok->quote_type == Q_DOUBLE)
		{
			count = count_split_token(tok->str);
			split_str = ft_calloc(count + 1, sizeof(char *));
			count = fill_split(split_str, tok->str) + 1;
			free(tok->str);
			tok->str = ft_strjoin_multi(count, split_str, NULL);
			free_split_str(split_str);
		}
		cur_lst = cur_lst->next;
	}
}
