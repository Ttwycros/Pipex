/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:18 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 18:58:19 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*temp;
	int		i;
	int		j;

	if (!s1 || !s2)
	{
		if (!s1 && s2)
			return (ft_strdup(s2));
		if (s1 && !s2)
			return (ft_strdup(s1));
		return (0);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!temp)
		return (0);
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		temp[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		temp[i++] = s2[j++];
	temp[i] = '\0';
	return (temp);
}
