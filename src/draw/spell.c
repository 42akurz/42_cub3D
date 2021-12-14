/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:06 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:33:07 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_sprint_spell(t_vars *vars)
{
	int	x;
	int	y;

	x = (int)floor(vars->calc->spritePosX);
	y = (int)floor(vars->calc->spritePosY);
	if (vars->key->sprint == true && vars->spelltaken == true)
		vars->calc->moveSpeed = vars->calc->frameTime * 12.0;
	if (vars->key->sprint == false)
		vars->calc->moveSpeed = vars->calc->frameTime * 5.0;
	if (vars->calc->posX >= floor(vars->calc->spritePosX)
		&& vars->calc->posX <= ceil(vars->calc->spritePosX)
		&& vars->calc->posY >= floor(vars->calc->spritePosY)
		&& vars->calc->posY <= ceil(vars->calc->spritePosY))
	{
		vars->spelltaken = true;
		vars->map[x][y] = '0';
	}
}
