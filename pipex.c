/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:31:55 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/08 16:52:36 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_1(t_commands	*cmds, char	**envp,
			char	*filename, t_pid	*processes)
{
	int	fd;

	fd = open(filename, O_RDONLY, 0777);
	if (fd < 0)
		error_cmd("Unable to open 'infile'", cmds);
	if (dup2(fd, STDIN_FILENO) < 0)
		error_cmd("Unable to dup infile and STDIN", cmds);
	if (dup2(processes->fifo[1], STDOUT_FILENO) < 0)
		error_cmd("Unable to dup fifo[1] and STDOUT", cmds);
	close(processes->fifo[0]);
	execve(cmds->command_1_and_path, cmds->command_1, envp);
	close(fd);
	close(processes->fifo[1]);
	exit(EXIT_FAILURE);
}

void	child_2(t_commands	*cmds, char	**envp,
			char	*filename, t_pid	*processes)
{
	int	fd;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (dup2(processes->fifo[0], STDIN_FILENO) < 0)
		error_cmd("Unable to dup fifo[0] and STDIN", cmds);
	if (dup2(fd, STDOUT_FILENO) < 0)
		error_cmd("Unable to dup outfile and STDOUT", cmds);
	close (processes->fifo[1]);
	execve(cmds->command_2_and_path, cmds->command_2, envp);
	close(fd);
	close(processes->fifo[0]);
	exit(EXIT_FAILURE);
}

void	pipex(t_commands	*cmds, t_pid	*processes,
			char	**envp, char	**argv)
{
	processes->child1 = fork();
	if (processes->child1 < 0)
		error_cmd("Forking one failed", cmds);
	if (!processes->child1)
		child_1(cmds, envp, argv[1], processes);
	processes->child2 = fork();
	if (processes->child2 < 0)
		error_cmd("Forking two failed", cmds);
	if (!processes->child2)
		child_2(cmds, envp, argv[4], processes);
	waitpid(0, NULL, 0);
}
