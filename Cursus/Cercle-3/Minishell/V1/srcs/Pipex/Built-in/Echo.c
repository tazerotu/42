/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:04:56 by ttas              #+#    #+#             */
/*   Updated: 2025/02/25 12:19:59 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../Includes/Executor.h"

// Verifies the number of arguments to see if it can print something
int echo_args(char **str)
{
	int i;
	i = 0;
	while(str[i])
		i++;
	return(i);
}

// if there is a param in the argument (ex: test a la valeur : $TEST) 
// it will verify if it exists
// get the value of the param
// and join the value of the param at the spot in the string it should be
char *print_variable(char *str)
{
	char *new;
	int i;
	int j;
	i = 0;
	while(str[i])
	{
		if(str[i] == '$')
		{
			j = i + 1;
			while(ft_isupper(str[j]))
				j++;
			
		}
		i++;
	}
	return(new);
}

// find the type of redirection and opens the file accordingly
int print_redirection(char **redir)
{
	int fd;
	if(redir[0] == ">")
		open(redir[1], O_RDWR | O_CREAT);
	else if(redir[0] == ">>")
		open(redir[1], O_RDWR | O_CREAT | O_APPEND);
	if(fd == -1)
	{
		perror(ERROR_FD);
		return(-1);
	}
	return(fd);
}

// Prints the argument, ex: "ceci est un test"
void echo_print(t_pipe *pipe, char *str)
{
	int fd;
	if(pipe->cmd->redir)
		fd = print_redirection(pipe->cmd->redir);
	else 
		fd = 1;
	ft_fprintf(fd, "%s", print_variable(str));
}

// The echo function, with only the -n option
void bi_echo(t_pipe *pipe)
{
	int i;
	int j;
	bool option;
	char **str;
	str = pipe->cmd->cmd;
	j = 1;
	option = false;
	if(echo_args(str) == 1)
		return ;
	if(str[j] == "-n")
	{
		option = true;
		j++;
	}
	while(str[j])
	{
		echo_print(pipe, str[j]);
		j++;
	}
}