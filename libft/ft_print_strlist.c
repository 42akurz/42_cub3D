/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_strlist.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:06:08 by fharing           #+#    #+#             */
/*   Updated: 2021/11/26 11:10:39 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_strlist(char **list)
{
	int	i;
	int	x;

	i = 0;
	while (list[i] != 0)
	{
		x = 0;
		while (list[i][x] != 0)
		{
			write(1, &list[i][x], 1);
			x++;
		}
		write(1, "\n", 1);
		i++;
	}
}
