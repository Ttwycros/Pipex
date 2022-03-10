/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:06:43 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 19:51:48 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t len)
{
	char		*temp;
	const char	*temp_src;
	int			counter;

	counter = 0;
	temp = dest;
	temp_src = src;
	if (!dest && !src)
		return (0);
	while (len)
	{
		*temp++ = *temp_src++;
		len--;
	}
	return (dest);
}
