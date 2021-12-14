/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:14:43 by fharing           #+#    #+#             */
/*   Updated: 2021/06/25 11:00:57 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_fill(char **a, char const *s, char c)
{
	int	x;
	int	j;
	int	flag;

	x = 0;
	j = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			a[x][j++] = *s;
			flag = 1;
		}
		if ((*s == c && flag == 1) || (flag == 1 && *(s + 1) == '\0'))
		{
			a[x++][j] = '\0';
			flag = 0;
			j = 0;
		}
		s++;
	}
	a[x] = 0;
}

static int	ft_length(char const *s, char c, int i)
{
	int	x;
	int	j;
	int	flag;

	x = 0;
	j = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			flag = 1;
		}
		if ((s[i] == c && flag == 1) || (flag == 1 && s[i + 1] == '\0'))
		{
			return (i);
		}
		i++;
	}
	return (i);
}

static int	ft_countwords(char const *s, char c)
{
	int	x;
	int	flag;

	x = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
			flag = 1;
		if ((*s == c && flag == 1) || (flag == 1 && *(s + 1) == '\0'))
		{
			x++;
			flag = 0;
		}
		s++;
	}
	return (x);
}

static int	ft_wordlength(char const *s, char c)
{
	int	x;
	int	flag;

	x = 0;
	flag = 0;
	while (*s)
	{
		if (*s != c)
		{
			flag = 1;
			x++;
		}
		if ((*s == c && flag == 1) || (s + 1) == '\0')
			return (x);
		s++;
	}
	return (x);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		words;
	int		mall;
	int		tmp;

	if (s == NULL)
		return (NULL);
	words = ft_countwords(s, c) + 1;
	arr = (char **)malloc(words * sizeof(char *));
	if (arr == NULL)
		return (NULL);
	i = 0;
	mall = 0;
	while (i < words - 1 && words != 0)
	{
		tmp = ft_wordlength((s + mall), c);
		mall = ft_length(s, c, mall);
		arr[i] = (char *)malloc(tmp + 1);
		if (arr[i] == NULL)
			return (NULL);
		i++;
	}
	ft_fill(arr, s, c);
	return (arr);
}
