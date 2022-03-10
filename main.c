/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 21:10:47 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/10 15:40:57 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*full_path(char	*s1, char	*s2)
{
	char	*temp;
	char	*res;

	temp = ft_strjoin(s1, "/");
	if (!temp)
		error_message("malloc fail");
	res = ft_strjoin(temp, s2);
	if (!res)
		error_message("malloc fail");
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
	if (access((cmd)->command_1[0], F_OK) == 0)
	{
		(cmd)->command_1_and_path = ft_strdup((cmd)->command_1[0]);
		if (!(cmd)->command_1_and_path)
			error_message("malloc fail");
	}
	else
		cmd->command_1_and_path = lol_kek(cmd, 1);
	if (access((cmd)->command_2[0], F_OK) == 0)
	{
		(cmd)->command_2_and_path = ft_strdup((cmd)->command_2[0]);
		if (!(cmd)->command_2_and_path)
			error_message("malloc fail");
	}
	else
		cmd->command_2_and_path = lol_kek(cmd, 2);
}

void	path_to_cmd(char	**envp, char	**argv, t_commands	*cmd)
{
	int		i;

	i = 0;
	while (envp[i] && ft_strncmp("PATH", envp[i], ft_strlen("PATH")))
		i++;
	if (!envp[i])
		error_message("No path in envp, соси душнила");
	if (envp[i])
		cmd->paths = ft_split(envp[i] + ft_strlen("PATH="), ':');
	i = 0;
	cmd->command_1 = ft_split(argv[2], ' ');
	cmd->command_2 = ft_split(argv[3], ' ');
	if (cmd->command_1 == 0 || cmd->command_2 == 0 || cmd->paths == 0)
		error_message("malloc fail");
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
