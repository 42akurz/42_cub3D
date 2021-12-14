/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:45 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:33:46 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_isdoor_2(t_vars *vars)
{
	if ((vars->key->door == true && vars->calc->hit == 1
			&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
		&& vars->map[(int)vars->calc->posX - 1]
		[(int)vars->calc->posY - 1] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX][(int)vars->calc->posY + 1] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX][(int)vars->calc->posY - 1] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX - 1][(int)vars->calc->posY] == '2'))
		return (1);
	return (0);
}

int	ft_isdoor(t_vars *vars)
{
	if ((vars->key->door == true && vars->calc->hit == 1
			&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
		&& vars->map[(int)vars->calc->posX][(int)vars->calc->posY] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY + 1] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY - 1] == '2')
	|| (vars->key->door == true && vars->calc->hit == 1
	&& vars->map[vars->calc->mapX][vars->calc->mapY] == '2'
	&& vars->map[(int)vars->calc->posX - 1][(int)vars->calc->posY + 1] == '2')
	|| ft_isdoor_2(vars) == 1)
		return (1);
	return (0);
}

void	ft_isdoor_open(t_vars *vars)
{
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX + 1]
		[(int)vars->calc->posY] == '3')
		vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX + 1]
		[(int)vars->calc->posY + 1] == '3')
		vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY + 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX + 1]
		[(int)vars->calc->posY - 1] == '3')
		vars->map[(int)vars->calc->posX + 1][(int)vars->calc->posY - 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX - 1]
		[(int)vars->calc->posY + 1] == '3')
		vars->map[(int)vars->calc->posX - 1][(int)vars->calc->posY + 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX - 1]
		[(int)vars->calc->posY - 1] == '3')
		vars->map[(int)vars->calc->posX - 1][(int)vars->calc->posY - 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX]
		[(int)vars->calc->posY + 1] == '3')
		vars->map[(int)vars->calc->posX][(int)vars->calc->posY + 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX]
		[(int)vars->calc->posY - 1] == '3')
		vars->map[(int)vars->calc->posX][(int)vars->calc->posY - 1] = '2';
	if (vars->key->doorclose == true && vars->map[(int)vars->calc->posX - 1]
		[(int)vars->calc->posY] == '3')
		vars->map[(int)vars->calc->posX - 1][(int)vars->calc->posY] = '2';
}

int	ft_validate_distance_to_door(t_vars *vars)
{
	int		re;
	double	x;

	re = 0;
	x = vars->calc->posX + vars->calc->dirX * vars->calc->moveSpeed;
	if ((vars->map[(int)(x + 0.2)][(int)(vars->calc->posY - 0.2)] != '3')
	&& (vars->map[(int)(x + 0.2)][(int)(vars->calc->posY)] != '3')
	&& (vars->map[(int)(x + 0.2)][(int)(vars->calc->posY + 0.2)] != '3')
	&& (vars->map[(int)(x - 0.2)][(int)(vars->calc->posY + 0.2)] != '3')
	&& (vars->map[(int)(x - 0.2)][(int)(vars->calc->posY - 0.2)] != '3')
	&& (vars->map[(int)(x - 0.2)][(int)(vars->calc->posY)] != '3')
	&& (vars->map[(int)(x)][(int)(vars->calc->posY)] != '3'))
		re++;
	x = vars->calc->posY + vars->calc->dirY * vars->calc->moveSpeed;
	if ((vars->map[(int)(vars->calc->posX - 0.2)][(int)(x + 0.2)] != '3')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x - 0.2)] != '3')
	&& (vars->map[(int)(vars->calc->posX - 0.2)][(int)(x)] != '3')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x + 0.2)] != '3')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x - 0.2)] != '3')
	&& (vars->map[(int)(vars->calc->posX + 0.2)][(int)(x)] != '3')
	&& (vars->map[(int)(vars->calc->posX)][(int)(x)] != '3'))
		re++;
	return (re);
}
