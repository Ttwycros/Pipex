/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/16 21:06:34 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/21 13:38:30 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static	int	ft_abs(int val)
{
	if (val >= 0)
		return (val);
	else
		return (-val);
}

static	char	*ft_malloc_and_sign(int *flag_plus, int lenght, int n)
{
	char	*temp;

	if (n < 0)
		*flag_plus = 1;
	if (n == 0)
	{
		temp = malloc(2);
		if (!temp)
			return (0);
		temp[0] = '0';
		temp[1] = '\0';
		return (temp);
	}
	temp = malloc(sizeof(char) * (lenght + *flag_plus + 1));
	if (!temp)
		return (0);
	if (*flag_plus == 1)
		*temp = '-';
	*(temp + lenght + *flag_plus) = '\0';
	return (temp);
}

char	*ft_itoa(int n)
{
	int		lenght;
	int		n_copy;
	char	*value;
	int		flag_plus;

	lenght = 0;
	n_copy = n;
	flag_plus = 0;
	while (n_copy != 0)
	{
		n_copy /= 10;
		lenght++;
	}
	value = ft_malloc_and_sign(&flag_plus, lenght, n);
	if (!value)
		return (0);
	while (lenght > 0)
	{
		*(value + (lenght - 1) + flag_plus) = ft_abs(n % 10) + '0';
		n /= 10;
		lenght--;
	}
	return (value);
}
