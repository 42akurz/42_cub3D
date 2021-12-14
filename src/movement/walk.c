/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walk.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:36 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:34:37 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_move_backwards_set_posy(t_vars *vars)
{
	double	x;

	x = vars->calc->posY - vars->calc->dirY * vars->calc->moveSpeed;
	if ((vars->map[(int)(vars->calc->posX - 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x + 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x - 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x)] != '2')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x + 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x - 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x)] != '2')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x - 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x + 0.2)] != '2'))
		vars->calc->posY -= vars->calc->dirY * vars->calc->moveSpeed;
}

void	ft_walk_backwards(t_vars *vars)
{
	double	i;

	i = vars->calc->posX - vars->calc->dirX * vars->calc->moveSpeed;
	if ((vars->map[(int)(i + 0.2)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY - 0.2)] != '2')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY)] != '2')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY - 0.2)] != '2')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY - 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY)] != '2'))
		vars->calc->posX -= vars->calc->dirX * vars->calc->moveSpeed;
	ft_move_backwards_set_posy(vars);
}

void	ft_move_right_set_posy(t_vars *vars)
{
	double	x;

	x = vars->calc->posY + vars->calc->planeY * vars->calc->moveSpeed;
	if ((vars->map[(int)(vars->calc->posX + 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x + 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x)] != '1')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x - 0.2)] != '1')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x + 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x)] != '2')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x - 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x + 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x - 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x + 0.2)] != '2')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x)] != '2')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x - 0.2)] != '2'))
		vars->calc->posY += vars->calc->planeY * vars->calc->moveSpeed;
}

void	ft_walk_right(t_vars *vars)
{
	double	i;

	i = vars->calc->posX + vars->calc->planeX * vars->calc->moveSpeed;
	if ((vars->map[(int)(i + 0.2)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY + 0.2)] != '1')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY - 0.2)] != '1')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY)] != '2')
	&& (vars->map[(int)(i + 0.2)][(int)(vars->calc->posY - 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY - 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i - 0.2)][(int)(vars->calc->posY)] != '2')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY + 0.2)] != '2')
	&& (vars->map[(int)(i)][(int)(vars->calc->posY - 0.2)] != '2'))
		vars->calc->posX += vars->calc->planeX * vars->calc->moveSpeed;
	ft_move_right_set_posy(vars);
}
