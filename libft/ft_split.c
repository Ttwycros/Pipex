/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ttwycros <ttwycros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 18:57:52 by ttwycros          #+#    #+#             */
/*   Updated: 2021/10/21 13:39:38 by ttwycros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdlib.h>

static	char	**ft_free(char **temp)
{
	int	i;

	i = -1;
	while (temp[++i])
		free(temp[i]);
	free(temp);
	return (0);
}

static	int	ft_counter(char const *s, char c)
{
	int	counter;

	if (!s[0])
		return (0);
	counter = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		if (*s == c)
		{
			counter++;
			while (*s && *s == c)
				s++;
			continue ;
		}
		s++;
	}
	if (s[-1] != c)
		counter++;
	return (counter);
}

static	int	ft_get_next_str(char **s_ptr, int lenght, char c)
{
	*s_ptr += lenght;
	lenght = 0;
	while (**s_ptr && **s_ptr == c)
		(*s_ptr)++;
	while ((*s_ptr)[lenght])
	{
		if ((*s_ptr)[lenght] == c)
			break ;
		lenght++;
	}
	return (lenght);
}

char	**ft_split(char const *s, char c)
{
	char	**temp;
	char	*s_copy;
	int		lenght;
	int		counter;
	int		i;

	if (!s)
		return (0);
	counter = ft_counter(s, c);
	temp = (char **)malloc(sizeof(char *) * (counter + 1));
	if (!temp)
		return (NULL);
	i = -1;
	s_copy = (char *)s;
	lenght = 0;
	while (++i < counter)
	{
		lenght = ft_get_next_str(&s_copy, lenght, c);
		temp[i] = (char *)malloc(sizeof(char) * (lenght + 1));
		if (!temp[i])
			return (ft_free(temp));
		ft_strlcpy(temp[i], s_copy, lenght + 1);
	}
	temp[i] = 0;
	return (temp);
}
