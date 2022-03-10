/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:11 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/20 12:48:19 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

char	*ft_strdup(const char *str)
{
	size_t	leght;
	char	*temp;

	leght = ft_strlen(str) + 1;
	temp = malloc(sizeof(char) * leght);
	if (temp)
		ft_memcpy(temp, str, leght);
	return (temp);
}
