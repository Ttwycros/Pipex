/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:59:51 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 22:05:39 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*temp;
	size_t	lenght;
	size_t	j;

	j = 0;
	if (!s)
		return (0);
	lenght = (size_t)ft_strlen(s + start);
	if (len > lenght)
		len = lenght;
	temp = malloc(sizeof(char) * (len + 1));
	if (!temp)
		return (0);
	while (s[j + start] && start < ft_strlen(s) && j < len)
	{
		temp[j] = s[j + start];
		j++;
	}
	temp[j] = '\0';
	return (temp);
}
