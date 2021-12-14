/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:23 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:33:24 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_player2(char c, t_math *calc)
{
	if (c == 'N')
	{
		calc->dirX = -1.00;
		calc->dirY = 0.00;
		calc->planeX = 0;
		calc->planeY = 0.66;
		return (1);
	}
	else if (c == 'S')
	{
		calc->dirX = 1.00;
		calc->dirY = 0.00;
		calc->planeX = 0;
		calc->planeY = -0.66;
		return (1);
	}
	return (0);
}

int	ft_player(char c, t_math *calc)
{
	if (c == 'W')
	{
		calc->dirX = 0.00;
		calc->dirY = -1.00;
		calc->planeX = -0.66;
		calc->planeY = 0;
		return (1);
	}
	else if (c == 'E')
	{
		calc->dirX = 0.00;
		calc->dirY = 1.00;
		calc->planeX = 0.66;
		calc->planeY = 0;
		return (1);
	}
	else if (ft_player2(c, calc))
		return (1);
	return (0);
}

void	ft_spritePos(t_math *calc, char c, int x, int y)
{
	if (c == '4')
	{
		calc->spritePosX = x + 0.5;
		calc->spritePosY = y + 0.5;
	}
}

void	ft_player_pos(t_vars *data, t_math *calc)
{
	int			y;
	int			x;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			ft_spritePos(calc, data->map[x][y], x, y);
			if (ft_player(data->map[x][y], calc))
			{
				calc->posX = (double)x + 0.5;
				calc->posY = (double)y + 0.5;
				calc->playerdir = data->map[x][y];
			}
			if (y > calc->maxY)
				calc->maxY = y;
			y++;
		}
		if (x > calc->maxX)
			calc->maxX = x;
		x++;
	}
}

t_math	*ft_init_calc(t_vars *data)
{
	t_math	*re;

	re = malloc(sizeof(t_math));
	re->maxX = 0;
	re->maxY = 0;
	re->spritePosX = 0;
	re->spritePosY = 0;
	ft_player_pos(data, re);
	re->time = 0;
	re->oldTime = 0;
	return (re);
}
