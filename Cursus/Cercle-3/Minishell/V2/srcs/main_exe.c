/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clai-ton <clai-ton@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 11:37:17 by ttas              #+#    #+#             */
/*   Updated: 2025/01/23 14:45:35 by clai-ton         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/Executor.h"

//temporary
static int	pipex_main(char **envp)
{
	t_pipe pipe;
	char *input;
    int i = 0;
	int j = 0;

    system("clear");
    while ( i < 10 )
    {
        input = readline("\033[0;32mMinishell>\033[0m");
        add_history(input);
		pipe = init(pipe, input, envp);
		printf("%i\n\n", pipe.n_pipe);
		j = 0;
		while(j < pipe.n_pipe)
		{
			printf("cmd : %s\n", pipe.cmd[j]);
			printf("len : %zu\n\n", ft_strlen(pipe.cmd[j]));
			j++;
		}
        i++;
    }
	return (0);
}

int main(int argc, char **argv, char **envp)
{
	(void) argc;
	(void) argv;
	return(pipex_main(envp));
}
