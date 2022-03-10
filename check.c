/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 15:32:38 by ttwycros          #+#    #+#             */
/*   Updated: 2022/03/10 15:41:00 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	check(char	**argv)
{
	while (*argv[2] && *argv[2] == ' ')
		argv[2]++;
	if (!*argv[2])
		error_message("command 1 doesn't exist");
	while (*argv[3] && *argv[2] == ' ')
		argv[3]++;
	if (!*argv[3])
		error_message("command 2 doesn't exist");
}
