/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:43:18 by fharing           #+#    #+#             */
/*   Updated: 2021/12/14 14:17:26 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_rotate_right(t_vars *vars)
{
	vars->calc->oldDirX = vars->calc->dirX;
	vars->calc->dirX = vars->calc->dirX * cos(vars->calc->rotSpeed)
		- vars->calc->dirY * sin(vars->calc->rotSpeed);
	vars->calc->dirY = vars->calc->oldDirX * sin(vars->calc->rotSpeed)
		+ vars->calc->dirY * cos(vars->calc->rotSpeed);
	vars->calc->oldPlaneX = vars->calc->planeX;
	vars->calc->planeX = vars->calc->planeX * cos(vars->calc->rotSpeed)
		- vars->calc->planeY * sin(vars->calc->rotSpeed);
	vars->calc->planeY = vars->calc->oldPlaneX * sin(vars->calc->rotSpeed)
		+ vars->calc->planeY * cos(vars->calc->rotSpeed);
}

void	ft_rotate_left(t_vars *vars)
{
	vars->calc->oldDirX = vars->calc->dirX;
	vars->calc->dirX = vars->calc->dirX * cos(-vars->calc->rotSpeed)
		- vars->calc->dirY * sin(-vars->calc->rotSpeed);
	vars->calc->dirY = vars->calc->oldDirX * sin(-vars->calc->rotSpeed)
		+ vars->calc->dirY * cos(-vars->calc->rotSpeed);
	vars->calc->oldPlaneX = vars->calc->planeX;
	vars->calc->planeX = vars->calc->planeX * cos(-vars->calc->rotSpeed)
		- vars->calc->planeY * sin(-vars->calc->rotSpeed);
	vars->calc->planeY = vars->calc->oldPlaneX * sin(-vars->calc->rotSpeed)
		+ vars->calc->planeY * cos(-vars->calc->rotSpeed);
}

void	ft_mouse_rotation(t_vars *vars)
{
	static double	prev_x = 0;
	int				x;
	int				y;

	mlx_mouse_get_pos(vars->win, &x, &y);
	mlx_mouse_move(vars->win, vars->win_width / 2, vars->win_height / 2);
	if (prev_x > vars->win_width / 2)
		ft_rotate_left(vars);
	else if (prev_x < vars->win_width / 2)
		ft_rotate_right(vars);
	prev_x = x;
}

void	ft_walk(t_vars *vars)
{
	if (vars->key->downFlag == true)
		ft_walk_backwards(vars);
	if (vars->key->rightFlag == true)
		ft_walk_right(vars);
	if (vars->key->leftFlag == true)
		ft_walk_left(vars);
	if (vars->key->upFlag == true)
		ft_walk_forward(vars);
}

void	ft_movement(t_vars *vars)
{
	ft_mouse_rotation(vars);
	ft_walk(vars);
	if (vars->key->arrowRightFlag == true)
		ft_rotate_right(vars);
	if (vars->key->arrowLeftFlag == true)
		ft_rotate_left(vars);
	ft_sprint_spell(vars);
}
