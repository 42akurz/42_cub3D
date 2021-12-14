/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:02 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:33:03 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_resetCounters(t_vars *vars)
{
	vars->minimap->a = 0;
	vars->minimap->b = 0;
	vars->minimap->u = 0;
	vars->minimap->o = 0;
	vars->minimap->pa = 0;
	vars->minimap->pb = 0;
}

void	ft_drawOnMinimap(t_vars *vars, int color, int pixelsToDraw)
{
	vars->minimap->pb = vars->minimap->b * pixelsToDraw;
	vars->minimap->o = 0;
	while (vars->minimap->o < pixelsToDraw)
	{
		vars->addr[vars->minimap->pa
			* (int)vars->win_width + vars->minimap->pb] = color;
		vars->minimap->pb++;
		vars->minimap->o++;
	}
}

void	ft_whatToDraw(t_vars *vars, int pixelsToDraw)
{
	char	c;

	c = vars->map[vars->minimap->a][vars->minimap->b];
	if (c == '1')
		ft_drawOnMinimap(vars, WALL, pixelsToDraw);
	else if (c == '2')
		ft_drawOnMinimap(vars, DOOR_CLOSED, pixelsToDraw);
	else if (c == '3')
		ft_drawOnMinimap(vars, DOOR_OPEN, pixelsToDraw);
	else if (c == '4')
		ft_drawOnMinimap(vars, SPELL, pixelsToDraw);
	else if (c == '0' || c == 'N' || c == 'S' || c == 'E' || c == 'W')
		ft_drawOnMinimap(vars, FLOOR, pixelsToDraw);
	if ((vars->minimap->a == (int)vars->calc->posX)
		&& (vars->minimap->b == (int)vars->calc->posY))
		ft_drawOnMinimap(vars, PLAYER, pixelsToDraw);
}

void	ft_minimap(t_vars *vars)
{
	int	pixelsToDraw;

	pixelsToDraw = 7;
	ft_resetCounters(vars);
	while (vars->map[vars->minimap->a])
	{
		vars->minimap->b = 0;
		while (vars->map[vars->minimap->a][vars->minimap->b])
		{
			vars->minimap->u = 0;
			vars->minimap->pa = vars->minimap->a * pixelsToDraw;
			while (vars->minimap->u < pixelsToDraw)
			{
				ft_whatToDraw(vars, pixelsToDraw);
				vars->minimap->u++;
				vars->minimap->pa++;
			}
			vars->minimap->b++;
		}
		vars->minimap->a++;
	}
}
