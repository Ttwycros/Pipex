/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:06:37 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 19:51:08 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*src;
	unsigned char	to_find;

	src = (unsigned char *)s;
	to_find = (unsigned char)c;
	while (n > 0)
	{
		if (*src == to_find)
			return (src);
		src++;
		n--;
	}
	return (0);
}
