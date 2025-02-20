/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parser.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 14:44:12 by clai-ton          #+#    #+#             */
/*   Updated: 2025/02/20 19:51:19 by clai-ton         ###   ########.fr       */
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
/*
void	test_quotes(void)
{
	char	str1[] = "je \'ne\' marche\" pas\' \"du\' tout";
	char	str2[] = "je \'ne\' marche\" pas \"non\' plus";
	char	str3[] = "je \'ne\' marche\" pas \'comme\' lautre";
	char	str4[] = "je \'suis\" sense\" marcher, \'hein?";
	char	str5[] = "je \"marche \":D";
	char	str6[] = "je \'marche \':)";
	char	str7[] = "en \"fait je \'marche! \":o";

	printf("%i; %s\n", check_incorrect_quotes(str1), str1);
	printf("%i; %s\n", check_incorrect_quotes(str2), str2);
	printf("%i; %s\n", check_incorrect_quotes(str3), str3);
	printf("%i; %s\n", check_incorrect_quotes(str4), str4);
	printf("%i; %s\n", check_incorrect_quotes(str5), str5);
	printf("%i; %s\n", check_incorrect_quotes(str6), str6);
	printf("%i; %s\n", check_incorrect_quotes(str7), str7);
}
*/
/*
void	test_trim(void)
{
	char	str1[] = "    test debut";
	char	str2[] = "test fin   ";
	char	str3[] = "test       milieu";
	char	str4[] = "     test   all    ";

	printf("debut: %s\n", ft_trim_token(str1));
	printf("fin: %s\n", ft_trim_token(str2));
	printf("milieu: %s\n", ft_trim_token(str3));
	printf("all: %s\n", ft_trim_token(str4));
}
*/

void	test_tokenizer_1_helper(char *src, char *idx)
{
	t_list **tok_lst;
	t_list *cur;
	t_tok *tok;

	printf("\n%s:\n", idx);
	tok_lst = ft_tokenize_1(src);
//printf("tok_lst: %p\n", tok_lst);
	cur = *tok_lst;
//printf("cur: %p\n", cur);
	while (cur)
	{
		if (cur->content)
		{
//printf("content: %p\n", cur->content);
			tok = (t_tok *) cur->content;
			printf("%s\n", tok->str);
		}
		cur = cur->next;
	}
	ft_lstclear(tok_lst, del_token_1);
}

void	test_tokenizer_1(void)
{
	char	str2[] = "test   without";
	//char	str3[] = "";//this one has yet to work
	char	str1a[] = "'  simplestart  'test simple + without";
	char	str1b[] = "test simple + without'  simpleend  '";
	char	str1c[] = "test '  simplemid  'simple + without";
	char	str4a[] = "\"  doublestart  \"test double + without";
	char	str4b[] = "test double + without\"  doubleend  \"";
	char	str4c[] = "test \"  doublemid  \"double + without";
	char	str5a[] = "test\"double\"'simple'";
	char	str5b[] = "test'simple'\"double\"";
	char	str5c[] = "\"double\"'simple'test";
	char	str5d[] = "'simple'\"double\"test";
	
	test_tokenizer_1_helper(str2, "2");
//	test_tokenizer_1_helper(str3, "3");
	test_tokenizer_1_helper(str1a, "1a");
	test_tokenizer_1_helper(str1b, "1b");
	test_tokenizer_1_helper(str1c, "1b");
	test_tokenizer_1_helper(str4a, "4a");
	test_tokenizer_1_helper(str4b, "4b");
	test_tokenizer_1_helper(str4c, "4c");
	test_tokenizer_1_helper(str5a, "5a");
	test_tokenizer_1_helper(str5b, "5b");
	test_tokenizer_1_helper(str5c, "5c");
	test_tokenizer_1_helper(str5d, "5d");
}

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	(void) envp;
	//return (parser_main());
	//test_quotes();
	//test_trim();
	test_tokenizer_1();
}