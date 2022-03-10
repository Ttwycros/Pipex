/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:44 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/21 13:39:56 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static	char	*ft_check(const char *haystack, const char *needle, size_t len)
{
	size_t	j;

	j = 1;
	while (needle[j]
		&& needle[j] == haystack[j] && j < len)
		j++;
	if (needle[j] == '\0')
		return ((char *)(haystack + j));
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	if (ft_strlen(needle) == 0)
		return ((char *)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		if (haystack[i] == needle[0])
			if (ft_check(haystack + i, needle, len - i))
				return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
