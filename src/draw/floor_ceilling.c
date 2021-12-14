/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:32:57 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:32:58 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_floor_ceilling(t_vars *vars, int x)
{
	int	u;
	int	z;

	u = 0;
	while (u < vars->calc->drawStart)
	{
		vars->tex->buff[u][x] = vars->ceillingcode;
		u++;
	}
	z = vars->calc->drawEnd;
	while (z < vars->win_height)
	{
		vars->tex->buff[z][x] = vars->floorcode;
		z++;
	}
}
