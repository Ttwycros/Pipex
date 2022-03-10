/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:57:28 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/21 13:39:15 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_abs(int val)
{
	if (val >= 0)
		return (val);
	else
		return (-val);
}

static	void	ft_lenght(int n, int *lenght)
{
	while (n > 9 || n < -9)
	{
		n /= 10;
		*lenght *= 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	int	lenght;
	int	n_copy;
	int	temp;

	lenght = 1;
	n_copy = n;
	if (fd < 0)
		return ;
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (n < 0)
		write(fd, "-", 1);
	ft_lenght(n, &lenght);
	while (lenght > 0)
	{
		temp = ft_abs(n / lenght) + 48;
		write(fd, &temp, 1);
		n %= lenght;
		lenght /= 10;
	}
}
