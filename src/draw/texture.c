/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:14 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:33:15 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	load_image(t_vars *vars, int *texture, char *path)
{
	t_imgTemp	t;

	t.img = mlx_xpm_file_to_image(vars->mlx, path, &t.img_width, &t.img_height);
	if (t.img == NULL)
		ft_error(6);
	t.addr = (int *)mlx_get_data_addr(t.img, &t.bits_per_pixel,
			&t.line_length, &t.endian);
	t.y = 0;
	while (t.y < t.img_height)
	{
		t.x = 0;
		while (t.x < t.img_width)
		{
			texture[t.img_width * t.y + t.x] = t.addr[t.img_width * t.y + t.x];
			t.x++;
		}
		t.y++;
	}
	mlx_destroy_image(vars->mlx, t.img);
}

void	load_texture(t_vars *vars)
{
	load_image(vars, vars->tex->texture[0], vars->north);
	load_image(vars, vars->tex->texture[1], vars->south);
	load_image(vars, vars->tex->texture[2], "./pics/door.xpm");
	load_image(vars, vars->tex->texture[3], "./pics/potion/spell1.xpm");
	load_image(vars, vars->tex->texture[4], "./pics/potion/spell2.xpm");
	load_image(vars, vars->tex->texture[5], "./pics/potion/spell3.xpm");
	load_image(vars, vars->tex->texture[6], "./pics/potion/spell4.xpm");
	load_image(vars, vars->tex->texture[7], vars->west);
	load_image(vars, vars->tex->texture[8], vars->east);
}

void	ft_chooseTextureForPixel(t_vars *vars)
{
	if (vars->calc->side == 0 && vars->calc->rayDirX < 0)
	{
		vars->tex->texColor
			= vars->tex->texture[0][64 * vars->tex->texY + vars->tex->texX];
	}
	else if (vars->calc->side == 0 && vars->calc->rayDirX >= 0)
	{
		vars->tex->texColor
			= vars->tex->texture[1][64 * vars->tex->texY + vars->tex->texX];
	}
	if (vars->calc->side == 1 && vars->calc->rayDirY < 0)
	{
		vars->tex->texColor
			= vars->tex->texture[7][64 * vars->tex->texY + vars->tex->texX];
	}
	else if (vars->calc->side == 1 && vars->calc->rayDirY >= 0)
	{
		vars->tex->texColor
			= vars->tex->texture[8][64 * vars->tex->texY + vars->tex->texX];
	}
}

/*
1.	Cast the texture coordinate to integer,
	and mask with (texHeight - 1) in case of overflow
2.	get color for pixel, depending on the texture we currently look at
3.	texture we use for walls depends on the direction we are looking at
4.	make color darker for y-sides:
	R, G and B byte each divided through two with a "shift" and an "and"
5.	write pixels of vertical stripe to buffer
*/
void	ft_writePixelsToBuffer(t_vars *vars, int x, int y)
{
	while (y < vars->calc->drawEnd)
	{
		vars->tex->texY = (int)vars->tex->texPos & (64 - 1);
		vars->tex->texPos += vars->tex->step;
		if (vars->map[vars->calc->mapX][vars->calc->mapY] == '2')
		{
			vars->tex->texColor
				= vars->tex->texture[2][64 * vars->tex->texY + vars->tex->texX];
		}
		else
			ft_chooseTextureForPixel(vars);
		if (vars->calc->side == 1)
			vars->tex->texColor = (vars->tex->texColor >> 1) & 8355711;
		vars->tex->buff[y][x] = vars->tex->texColor;
		y++;
	}
}

/*
1.	calculate value of wallX = the exact value where the wall was hit.
	This is required to know which x-coordinate of the texture we have to use
2.	texX = x coordinate on the texture
3.	step =  How much to increase the texture coordinate per screen pixel
4.	texPos = Starting texture coordinate
*/
void	ft_draw_texture(t_vars *vars, int x)
{
	int	y;

	if (vars->calc->side == 0)
	{
		vars->tex->wallX
			= vars->calc->posY + vars->calc->perpWallDist * vars->calc->rayDirY;
	}
	else
	{
		vars->tex->wallX
			= vars->calc->posX + vars->calc->perpWallDist * vars->calc->rayDirX;
	}
	vars->tex->wallX -= floor(vars->tex->wallX);
	vars->tex->texX = (int)(vars->tex->wallX * ((double)64));
	if (vars->calc->side == 0 && vars->calc->rayDirX > 0)
		vars->tex->texX = 64 - vars->tex->texX - 1;
	if (vars->calc->side == 1 && vars->calc->rayDirY < 0)
		vars->tex->texX = 64 - vars->tex->texX - 1;
	vars->tex->step = 1.0 * 64 / vars->calc->lineHeight;
	vars->tex->texPos = (vars->calc->drawStart - vars->win_height
			/ 2 + vars->calc->lineHeight / 2) * vars->tex->step;
	y = vars->calc->drawStart;
	ft_writePixelsToBuffer(vars, x, y);
}
