/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:53 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:32:54 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	draw(t_vars *vars)
{
	int	y;
	int	x;

	y = 0;
	while (y < vars->win_height)
	{
		x = 0;
		while (x < vars->win_width)
		{
			vars->addr[y * (int)vars->win_width + x] = vars->tex->buff[y][x];
			x++;
		}
		y++;
	}
	ft_minimap(vars);
	ft_crosshair(vars);
	mlx_put_image_to_window(vars->mlx, vars->win, vars->img, 0, 0);
}
