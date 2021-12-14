/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 09:09:21 by fharing           #+#    #+#             */
/*   Updated: 2021/06/23 09:36:16 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_print(int *tmp, int i, int fd)
{
	char	print;

	while (i >= 0)
	{
		print = tmp[i] + 48;
		write(fd, &print, 1);
		i--;
	}
}

static int	ft_sign(int n, int fd)
{
	if (n < 0)
	{
		n = n * -1;
		write(fd, "-", 1);
	}
	return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	tmp[15];
	int	i;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	n = ft_sign(n, fd);
	if (n == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	while (n > 0)
	{
		tmp[i] = n % 10;
		n = n / 10;
		i++;
	}
	ft_print(tmp, i - 1, fd);
}
