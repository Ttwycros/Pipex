/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:57:14 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 22:31:09 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	unsigned char			*temp_dest;
	const unsigned char		*temp_src;
	size_t					i;

	temp_dest = dest;
	temp_src = src;
	if (!temp_dest && !temp_src)
		return (0);
	if (temp_dest > temp_src)
	{
		while (len > 0)
		{
			*(temp_dest + len - 1) = *(temp_src + len - 1);
			len--;
		}
	}
	i = -1;
	while (++i < len)
		*(temp_dest + i) = *(temp_src + i);
	return (dest);
}
