/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:49 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/20 18:19:17 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		counter;
	char	*temp;

	counter = 0;
	temp = (char *)s;
	while (*(s + counter))
	{
		if ((*(s + counter) == (char)c))
			temp = (char *)(s + counter);
		counter++;
	}
	if (*temp == (char)c)
		return (temp);
	if (c == '\0')
		return ((char *)s + ft_strlen(s));
	return (0);
}
