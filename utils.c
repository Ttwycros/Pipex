/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:02:06 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/08 16:31:54 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error_message(char	*message)
{
	ft_putstr_fd("Error: ", 2);
	ft_putendl_fd(message, 2);
	exit(EXIT_FAILURE);
}

static void	free_array(char	**array)
{
	int	i;

	i = 0;
	if (array)
	{
		while (array[i])
			free(array[i++]);
		free(array);
	}
}

void	protected_clean(t_commands	*cmd)
{
	free_array(cmd->command_1);
	free_array(cmd->command_2);
	free_array(cmd->paths);
	if (cmd->command_1_and_path)
		free(cmd->command_1_and_path);
	if (cmd->command_2_and_path)
		free(cmd->command_2_and_path);
}

void	error_cmd(char	*message, t_commands	*cmd)
{
	protected_clean(cmd);
	error_message(message);
}
