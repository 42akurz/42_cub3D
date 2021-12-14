/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   crosshair.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:46 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:32:47 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_crosshair(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
		{
			if (((x == vars->win_width / 2 && y < vars->win_height
						/ 2 + 10 && y > vars->win_height / 2 - 10)
					|| (y == vars->win_height / 2 && x < vars->win_width
						/ 2 + 10 && x > vars->win_width / 2 - 10)
					|| (x == vars->win_width / 2 + 1 && y < vars->win_height
						/ 2 + 10 && y > vars->win_height / 2 - 10)
					|| (y == vars->win_height / 2 + 1 && x < vars->win_width
						/ 2 + 10 && x > vars->win_width / 2 - 10)))
				vars->addr[y * (int)vars->win_width + x] = 123546;
			x++;
		}
		y++;
	}
}
