/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttas <ttas@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 12:23:16 by ttas              #+#    #+#             */
/*   Updated: 2025/01/20 12:24:43 by ttas             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/Executor.h"

void free_pipe(t_pipe)
{
	free(pipe.cmd);
	free(pipe.envp);
	
}