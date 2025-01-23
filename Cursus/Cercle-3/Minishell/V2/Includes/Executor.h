/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:15:50 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 09:53:54 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

// Includes
# include "./libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>

// Struct
typedef struct s_splice
{
	int length;
	char *str;
}	t_splice;

typedef struct s_command
{
	char **redir_tok;
	char **arg_tok;
}	t_cmd;

typedef struct s_pipe
{
	int n_pipe;
	int semicolon;
	char **envp;
	t_cmd *cmd;
}	t_pipe;

// Functions
	// Init
t_pipe init(t_pipe pipe, char *str, char **envp);
// t_splice *splicer(t_pipe pipe, char *str);

	// Command initialization
void verify_semicolon(void);
void verify_cmd(void);
void here_doc(void);
void split(void);

	// Execute
void execute(void);
void get_path(void);
void child_process(void);
void parent_process(void);
// with option -n
void echo(char *option, char *str);
// with absolute or relative path
void cd(char *path);
void pwd(void);
void export(void);
void unset(void);
void env(void);
void exit(void);

#endif