/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:59:41 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/20 18:19:18 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	int		remaining_lenght;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	remaining_lenght = ft_strlen(s1);
	while (ft_strchr(set, s1[remaining_lenght])
		&& remaining_lenght > 0)
		remaining_lenght--;
	if (!remaining_lenght)
	{
		return (ft_strdup(""));
	}
	return (ft_substr(s1, 0, remaining_lenght + 1));
}
