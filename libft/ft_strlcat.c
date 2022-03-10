/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:25 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 18:58:25 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		destsize;
	size_t		srcsize;
	size_t		counter;

	destsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	counter = 0;
	if (destsize >= size)
		return (srcsize + size);
	while (*(src + counter) != '\0'
		&& destsize + counter < size - 1)
	{
		*(dst + destsize + counter) = *(src + counter);
		counter++;
	}
	*(dst + destsize + counter) = '\0';
	return (destsize + srcsize);
}
