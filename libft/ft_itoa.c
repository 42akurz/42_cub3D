/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 11:19:33 by fharing           #+#    #+#             */
/*   Updated: 2021/06/23 09:39:23 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_get_digits(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static int	ft_MAXINT(int n, char *tmp)
{
	if (n == -2147483648)
	{
		tmp[0] = '-';
		tmp[1] = '2';
		tmp[2] = '1';
		tmp[3] = '4';
		tmp[4] = '7';
		tmp[5] = '4';
		tmp[6] = '8';
		tmp[7] = '3';
		tmp[8] = '6';
		tmp[9] = '4';
		tmp[10] = '8';
		tmp[11] = '\0';
		return (1);
	}
	return (0);
}

static void	ft_zero(char *a)
{
	if (ft_strlen(a) == 0)
	{
		a[0] = '0';
		a[1] = '\0';
		return ;
	}
}

static void	ft_turn(char *a, int minus)
{
	int		i;
	int		x;
	char	tmp;

	i = 0;
	x = ft_strlen(a) - 1;
	if (minus == 1)
	{
		a[x + 1] = '-';
		a[x + 2] = '\0';
		x++;
	}
	if (minus == 0)
		a[x + 1] = '\0';
	while (i < x)
	{
		tmp = a[x];
		a[x] = a[i];
		a[i] = tmp;
		i++;
		x--;
	}
	if (ft_strlen(a) == 0)
		ft_zero(a);
}

char	*ft_itoa(int n)
{
	char	*tmp;
	int		i;
	int		minus;

	i = 0;
	minus = 0;
	tmp = (char *)malloc(ft_get_digits(n) + 1);
	if (tmp == NULL)
		return (NULL);
	if (ft_MAXINT(n, tmp) == 1)
		return (tmp);
	if (n < 0)
	{
		minus = 1;
		n = n * -1;
	}
	while (n > 0)
	{
		tmp[i++] = n % 10 + 48;
		n = n / 10;
	}
	tmp[i] = '\0';
	ft_turn(tmp, minus);
	return (tmp);
}
