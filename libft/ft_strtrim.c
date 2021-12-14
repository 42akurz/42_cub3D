/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:10:33 by fharing           #+#    #+#             */
/*   Updated: 2021/12/14 10:38:43 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_substring(char const *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	i;
	size_t	x;

	i = start;
	x = 0;
	tmp = (char *)malloc(len + 2 - start);
	if (tmp == NULL)
		return (NULL);
	if (start == 0 && len == 0)
	{
		tmp [0] = '\0';
		return (tmp);
	}
	while (s[i] != '\0' && i <= len)
	{
		tmp[x] = s[i];
		i++;
		x++;
	}
	tmp[x] = '\0';
	return (tmp);
}

static int	ft_end(char const *s1, char const *set)
{
	int		i;
	int		x;
	int		flag;

	i = ft_strlen(s1) - 1;
	while (i >= 0)
	{
		x = 0;
		flag = 0;
		while (set[x] != '\0' && flag != 1)
		{
			if (s1[i] == set[x])
				flag = 1;
			x++;
		}
		if (flag == 0)
			return (i);
		i--;
	}
	return (0);
}

static int	ft_front(char const *s1, char const *set)
{
	int		i;
	int		x;
	int		flag;

	i = 0;
	while (s1[i] != '\0')
	{
		x = 0;
		flag = 0;
		while (set[x] != '\0' && flag != 1)
		{
			if (s1[i] == set[x])
				flag = 1;
			x++;
		}
		if (flag == 0)
			return (i);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*re;
	int		start;
	int		end;

	if (s1 == NULL)
		return (NULL);
	start = ft_front(s1, set);
	end = ft_end(s1, set);
	re = ft_substring(s1, start, end);
	return (re);
}
