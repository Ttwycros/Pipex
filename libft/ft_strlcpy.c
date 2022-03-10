/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:28 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 18:58:32 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t len)
{
	size_t	counter;
	size_t	src_size;

	counter = 0;
	src_size = ft_strlen(src);
	if (!len)
		return (src_size);
	while (src[counter] && counter < (len - 1))
	{
		dest[counter] = src[counter];
		counter++;
	}
	dest[counter] = '\0';
	return (src_size);
}
