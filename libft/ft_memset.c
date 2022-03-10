/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:57:18 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 19:53:47 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *memptr, int val, size_t num)
{
	unsigned char	*temp;

	temp = memptr;
	while (num > 0)
	{
		*temp = (char) val;
		temp++;
		num--;
	}
	return (memptr);
}
