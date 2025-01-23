/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:12 by clai-ton          #+#    #+#             */
/*   Updated: 2025/01/23 14:56:00 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/lexer_parser.h"

//temporary
/*
static int	parser_main(void)
{
	char *input = NULL;
    int i = 0;
	t_list *cmds;
	t_cmd	*cur_cmd;

	system("clear");
	do
	{
		input = readline("\033[0;32mMinishell>\033[0m");
        add_history(input);
		cmds = parse_line(input);
		while (cmds)
		{
			cur_cmd = (t_cmd *) cmds->content;
			printf("Redirections:");
			while (cur_cmd->redir_tok[i])
				printf(" %s", cur_cmd->redir_tok[i++]);
			i = 0;
			printf("\nCommand with arguments:");
			while (cur_cmd->arg_tok[i])
				printf(" %s", cur_cmd->arg_tok[i++]);
			printf("\n");
		}
	} while (input && ft_strncmp("exit", input, 5));
	return (0);
}
*/
void	test_quotes(void)
{
	char	str1[] = "je \'ne\' marche\" pas\' \"du\' tout";
	char	str2[] = "je \'ne\' marche\" pas \"non\' plus";
	char	str3[] = "je \'ne\' marche\" pas \'comme\' lautre";
	char	str4[] = "je \'suis\" sense\" marcher, \'hein?";
	char	str5[] = "je \"marche \":D";
	char	str6[] = "je \'marche \':)";

	printf("%i; %s\n", check_incorrect_quotes(str1), str1);
	printf("%i; %s\n", check_incorrect_quotes(str2), str2);
	printf("%i; %s\n", check_incorrect_quotes(str3), str3);
	printf("%i; %s\n", check_incorrect_quotes(str4), str4);
	printf("%i; %s\n", check_incorrect_quotes(str5), str5);
	printf("%i; %s\n", check_incorrect_quotes(str6), str6);
}

int main(void)
{
	//return (parser_main());
	test_quotes();
}