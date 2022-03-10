/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:58:05 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/19 18:58:06 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strchr(const char *s, int c)
{
	int	counter;

	counter = 0;
	while (*(s + counter) && !(*(s + counter) == (char)c))
		counter++;
	if (*(s + counter) == (char)c)
		return ((char *)(s + counter));
	return (0);
}
