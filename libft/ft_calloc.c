/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:06:16 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 19:54:26 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

void	*ft_calloc(size_t number, size_t size)
{
	char	*temp;

	if (number == 0 || size == 0)
	{
		number = 1;
		size = 1;
	}
	temp = malloc(number * size);
	if (temp)
		ft_bzero(temp, number * size);
	return (temp);
}
