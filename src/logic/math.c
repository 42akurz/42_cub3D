/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:04 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:34:05 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

/*
1.	calculate ray position and direction
2.	cameraX = x-coordinate on the camera plane,
	that represents the current x-coordinate of the screen
3.	rayDir = Direction of the current ray
4.	mapX, Y = which box of the map, the current ray is in
5.	deltaDist = length of ray from one x or y-side to next x or y-side
*/
void	ft_rayPosition_and_Direction(t_vars *vars, int x)
{
	vars->calc->cameraX = 2 * x / vars->win_width - 1;
	vars->calc->rayDirX
		= vars->calc->dirX + vars->calc->planeX * vars->calc->cameraX;
	vars->calc->rayDirY
		= vars->calc->dirY + vars->calc->planeY * vars->calc->cameraX;
	vars->calc->mapX = (int)vars->calc->posX;
	vars->calc->mapY = (int)vars->calc->posY;
	if (vars->calc->rayDirX == 0)
		vars->calc->deltaDistX = 1e30;
	else
		vars->calc->deltaDistX = fabs(1 / vars->calc->rayDirX);
	if (vars->calc->rayDirY == 0)
		vars->calc->deltaDistY = 1e30;
	else
		vars->calc->deltaDistY = fabs(1 / vars->calc->rayDirY);
}

/*
1.	step = what direction to step in x or y-direction (either +1 or -1)
2.	sideDist = length of ray from current position to next x or y-side
*/
void	ft_step_and_sideDistance(t_vars *vars)
{
	if (vars->calc->rayDirX < 0)
	{
		vars->calc->stepX = -1;
		vars->calc->sideDistX = (vars->calc->posX - vars->calc->mapX)
			* vars->calc->deltaDistX;
	}
	else
	{
		vars->calc->stepX = 1;
		vars->calc->sideDistX = (vars->calc->mapX + 1.0 - vars->calc->posX)
			* vars->calc->deltaDistX;
	}
	if (vars->calc->rayDirY < 0)
	{
		vars->calc->stepY = -1;
		vars->calc->sideDistY = (vars->calc->posY - vars->calc->mapY)
			* vars->calc->deltaDistY;
	}
	else
	{
		vars->calc->stepY = 1;
		vars->calc->sideDistY = (vars->calc->mapY + 1.0 - vars->calc->posY)
			* vars->calc->deltaDistY;
	}
}

void	ft_DDA_hitCheck(t_vars *vars)
{
	if (!(vars->calc->mapX < vars->calc->maxX && vars->calc->mapX >= 0))
		vars->calc->hit = 1;
	if (!(vars->calc->mapY < vars->calc->maxY && vars->calc->mapY >= 0))
		vars->calc->hit = 1;
	if (vars->map[vars->calc->mapX][vars->calc->mapY] == '1'
		|| vars->map[vars->calc->mapX][vars->calc->mapY] == '2')
		vars->calc->hit = 1;
}

/*
1.	jump to next map square, either in x-direction, or in y-direction
2.	hit = was there a wall hit? (ray hit a wall or door)
3.	side = was a NS or a EW wall hit? (which side of the wall/door)
*/
void	ft_DDA_algorithm(t_vars *vars)
{
	vars->calc->hit = 0;
	while (vars->calc->hit == 0)
	{
		if (vars->calc->sideDistX < vars->calc->sideDistY)
		{
			vars->calc->sideDistX += vars->calc->deltaDistX;
			vars->calc->mapX += vars->calc->stepX;
			vars->calc->side = 0;
		}
		else
		{
			vars->calc->sideDistY += vars->calc->deltaDistY;
			vars->calc->mapY += vars->calc->stepY;
			vars->calc->side = 1;
		}
		if (vars->calc->mapX < 0)
			vars->calc->mapX = vars->calc->mapX * -1;
		if (vars->calc->mapY < 0)
			vars->calc->mapY = vars->calc->mapY * -1;
		ft_DDA_hitCheck(vars);
	}
}

/*
1.	Calculate distance from player to wall/door (perpWallDist)
2.	Calculate height of line to draw on screen (lineHeight)
3.	side = was a NS or a EW wall hit? (which side of the wall/door)
4.	calculate lowest and highest pixel to fill in current stripe (drawS/E)
*/
void	ft_drawStart_and_drawEnd(t_vars *vars)
{
	if (vars->calc->side == 0)
		vars->calc->perpWallDist
			= (vars->calc->sideDistX - vars->calc->deltaDistX);
	else
		vars->calc->perpWallDist
			= (vars->calc->sideDistY - vars->calc->deltaDistY);
	vars->calc->lineHeight = (int)(vars->win_height / vars->calc->perpWallDist);
	vars->calc->drawStart
		= -vars->calc->lineHeight / 2 + (int)vars->win_height / 2;
	if (vars->calc->drawStart < 0)
		vars->calc->drawStart = 0;
	vars->calc->drawEnd
		= vars->calc->lineHeight / 2 + (int)vars->win_height / 2;
	if (vars->calc->drawEnd >= (int)vars->win_height)
		vars->calc->drawEnd = (int)vars->win_height - 1;
}
