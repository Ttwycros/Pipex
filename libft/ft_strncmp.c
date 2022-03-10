/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:41 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 19:54:36 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*temp_s1;
	unsigned char	*temp_s2;

	temp_s1 = (unsigned char *)s1;
	temp_s2 = (unsigned char *)s2;
	while ((*temp_s1 && *temp_s2) && n != 0)
	{
		if (*temp_s1 != *temp_s2)
			return ((*temp_s1 - *temp_s2));
		temp_s1++;
		temp_s2++;
		n--;
	}
	if (n != 0)
		return ((*temp_s1 - *temp_s2));
	return (0);
}
