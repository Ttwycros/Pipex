/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:01:22 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/10 15:41:13 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_pid
{
	int		fifo[2];
	pid_t	child1;
	pid_t	child2;
}				t_pid;

typedef struct s_commands
{
	char	**command_1;
	char	**command_2;
	char	**paths;
	char	*command_1_and_path;
	char	*command_2_and_path;
}				t_commands;

void	error_message(char	*message);
void	check(char	**argv);
void	error_cmd(char	*message, t_commands	*cmd);
void	pipex(t_commands	*cmds, t_pid	*processes,
			char	**envp, char	**argv);
void	protected_clean(t_commands	*cmd);

#endif