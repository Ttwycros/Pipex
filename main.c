/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:10:47 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/04 16:22:01 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*full_path(char	*s1, char	*s2)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(s1, "/");
	res = ft_strjoin(temp, s2);
	free(temp);
	return (res);
}

char	*lol_kek(t_commands	*cmd, int number)
{
	int		i;
	char	*temp;

	i = 0;
	while ((cmd)->paths[i])
	{
		if (number == 1)
			temp = full_path((cmd)->paths[i], (cmd)->command_1[0]);
		if (number == 2)
			temp = full_path((cmd)->paths[i], (cmd)->command_2[0]);
		if (!access(temp, F_OK))
			return (temp);
		free(temp);
		temp = NULL;
		i++;
	}
	return (NULL);
}

void	path_find(t_commands	*cmd)
{
	if (!access((cmd)->command_1[0], F_OK))
		(cmd)->command_1_and_path = (cmd)->command_1[0];
	else
		cmd->command_1_and_path = lol_kek(cmd, 1);
	if (!access((cmd)->command_2[0], F_OK))
		(cmd)->command_2_and_path = (cmd)->command_2[0];
	else
		cmd->command_2_and_path = lol_kek(cmd, 2);
}

void	path_to_cmd(char	**envp, char	**argv, t_commands	*cmd)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	if (envp[i])
		cmd->paths = ft_split(envp[i] + ft_strlen("PATH="), ':');
	i = 0;
	cmd->command_1 = ft_split(argv[2], ' ');
	cmd->command_2 = ft_split(argv[3], ' ');
	path_find(cmd);
	if (!cmd->command_1_and_path
		|| !cmd->command_2_and_path)
		error_cmd("command 1 and/or command 2 don't exist", cmd);
}

int	main(int argc, char	**argv, char	**envp)
{
	t_pid		processes;
	t_commands	cmd;

	if (argc != 5)
		error_message("Enter correct number of elements");
	check(argv);
	if (pipe(processes.fifo) == -1)
		error_message("Pipe failed");
	path_to_cmd(envp, argv, &cmd);
	pipex(&cmd, &processes, envp, argv);
	protected_clean(&cmd);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	// pid_t	fork(void);
	// int		pipe(int fifo[2]);
	pid_t	child_pid;
	int		fifo[2];
	char	buf[80];
	int		status;
	pid_t	pid1;
	pid_t	pid2;
	

//создание пайпа
	if (pipe(fifo) == -1)
	{
		printf("error pipe");
		return (1);
	}


	pid1 = fork();
	if (pid1 == -1)
	{
		exit(-1);
	}
	if (pid1 == 0)
	{
		printf("pid1 \n");
		if (dup2(fifo[1], STDOUT_FILENO) == -1)
			exit (4);
		PIPES_CLOSE(fifo);
		if (execlp("/bin/sh", "sh", "-c", argv[1], 0) == -1)
		{
			printf("execpl error \n");
			exit (5);
		}
	}

	pid2 = fork();
	if (pid2 == -1)
	{
		exit(-1);
	}
	if (pid2 == 0)
	{
		printf("pid2 \n");
		if (dup2(fifo[0], STDIN_FILENO) == -1)
			exit (7);
		PIPES_CLOSE(fifo);
		if (execlp("/bin/sh", "sh", "-c", argv[2], 0) == -1)
		{
			printf("execpl error \n");
			exit (8);
		}
	}
	PIPES_CLOSE(fifo);
	if (waitpid(pid1, &fifo[0], 0) != pid1 || waitpid(pid2, &fifo[1], 0) != pid2)
		printf("waitpid error \n");
	return (fifo[0] + fifo[1]);
}

void	pipex(t_cmd	*cmds, t_proccess	*proc, char	**envp, char	**argv)
{
	proc->child1 = fork();
	if (proc->child1 < 0)
		error_cmd("ERROR: Forking one failed", &cmds);
	if (!proc->child1)
		child_1(cmds, envp, argv[1], proc);
	proc->child2 = fork();
	if (proc->child2 < 0)
		error_cmd("ERROR: Forking two failed", &cmds);
	if (!proc->child2)
		child_2(cmds, envp, argv[4], proc);
	waitpid(0, NULL, 0);
}
*/