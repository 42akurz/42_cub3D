/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 15:23:09 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 16:33:24 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_sprite_animation(t_vars *vars)
{
	vars->global_count++;
	if (vars->global_count == 20)
	{
		vars->spellNumber++;
		if (vars->spellNumber == 7)
			vars->spellNumber = 3;
		vars->global_count = 0;
	}
}

/*
1.	loop through every pixel of the current stripe
2.	d = 256 and 128 factors to avoid floats
3.	get current color from the texture
4.	paint pixel if it isn't black, black is the invisible color
*/
void	ft_spriteStripeLoop(t_vars *vars, int stripe)
{
	int	y;

	y = vars->sprite->drawStartY;
	while (y < vars->sprite->drawEndY)
	{
		vars->sprite->d = (y - vars->sprite->vMoveScreen)
			* 256 - vars->win_height * 128 + vars->sprite->spriteHeight * 128;
		vars->sprite->texY = ((vars->sprite->d * 64)
				/ vars->sprite->spriteHeight) / 256;
		vars->sprite->color = vars->tex->texture[vars->spellNumber]
		[64 * vars->sprite->texY + vars->sprite->texX];
		if ((vars->sprite->color & 0x00FFFFFF) != 0)
			vars->tex->buff[y][stripe] = vars->sprite->color;
		y++;
	}
}

/*
1.	loop through every vertical stripe of the sprite on screen
2.	the conditions in the if are:
	1) it's in front of camera plane so you don't see things behind you
	2) it's on the screen (left)
	3) it's on the screen (right)
	4) ZBuffer, with perpendicular distance
3.	loop through every pixel of the current stripe
*/
void	ft_writeSpritePixelToBuffer(t_vars	*vars)
{
	int	stripe;

	stripe = vars->sprite->drawStartX;
	while (stripe < vars->sprite->drawEndX)
	{
		vars->sprite->texX = (int)(256 * (stripe - (-vars->sprite->spriteWidth
						/ 2 + vars->sprite->spriteScreenX))
				* 64 / vars->sprite->spriteWidth) / 256;
		if (vars->sprite->transformY > 0 && stripe > 0
			&& stripe < vars->win_width
			&& vars->sprite->transformY < vars->sprite->ZBuffer[stripe])
			ft_spriteStripeLoop(vars, stripe);
		stripe++;
	}
}

/*
1.	drawStart, -End = calculate lowest and highest pixel to fill in current stripe
2.	spriteWidth = calculate width of the sprite
*/
void	ft_drawStart_drawEnd_and_Width(t_vars *vars)
{
	if (vars->sprite->drawStartY < 0)
		vars->sprite->drawStartY = 0;
	vars->sprite->drawEndY = vars->sprite->spriteHeight
		/ 2 + vars->win_height / 2 + vars->sprite->vMoveScreen;
	if (vars->sprite->drawEndY >= vars->win_height)
		vars->sprite->drawEndY = vars->win_height - 1;
	vars->sprite->spriteWidth = fabs(vars->win_height
			/ vars->sprite->transformY)
		/ vars->sprite->sizeFactor;
	vars->sprite->drawStartX = -vars->sprite->spriteWidth
		/ 2 + vars->sprite->spriteScreenX;
	if (vars->sprite->drawStartX < 0)
		vars->sprite->drawStartX = 0;
	vars->sprite->drawEndX = vars->sprite->spriteWidth
		/ 2 + vars->sprite->spriteScreenX;
	if (vars->sprite->drawEndX >= vars->win_width)
		vars->sprite->drawEndX = vars->win_width - 1;
}

/*
1.	spriteX, spriteY = translate sprite position to relative to camera
2.	transformY, transformX = transform sprite with the inverse camera matrix.
	what would be "depth" inside 3D screen
3.	spriteDistanceFromGround can be changed to make it float higher
4.	sizeFactor can be changed to resize sprite
5.	spriteHeight = calculate height of the sprite on screen
	using 'transformY' instead of the real distance prevents fisheye
6.	drawStart, -End = calculate lowest and highest pixel to fill in current stripe
7.	spriteWidth = calculate width of the sprite
8.	loop through every vertical stripe of the sprite on screen
*/
void	ft_draw_sprite(t_vars *vars)
{
	vars->sprite->spriteX = vars->calc->spritePosX - vars->calc->posX;
	vars->sprite->spriteY = vars->calc->spritePosY - vars->calc->posY;
	vars->sprite->invDet = 1.0 / (vars->calc->planeX
			* vars->calc->dirY - vars->calc->dirX * vars->calc->planeY);
	vars->sprite->transformX = vars->sprite->invDet * (vars->calc->dirY
			* vars->sprite->spriteX - vars->calc->dirX * vars->sprite->spriteY);
	vars->sprite->transformY = vars->sprite->invDet * (-vars->calc->planeY
			* vars->sprite->spriteX + vars->calc->planeX
			* vars->sprite->spriteY);
	vars->sprite->spriteScreenX = (int)((vars->win_width / 2)
			* (1 + vars->sprite->transformX / vars->sprite->transformY));
	vars->sprite->spriteDistanceFromGround = 256;
	vars->sprite->vMoveScreen = (int)(vars->sprite->spriteDistanceFromGround
			/ vars->sprite->transformY);
	vars->sprite->sizeFactor = 2;
	vars->sprite->spriteHeight = fabs(vars->win_height
			/ vars->sprite->transformY) / vars->sprite->sizeFactor;
	vars->sprite->drawStartY = -vars->sprite->spriteHeight
		/ 2 + vars->win_height
		/ 2 + vars->sprite->vMoveScreen;
	ft_drawStart_drawEnd_and_Width(vars);
	ft_writeSpritePixelToBuffer(vars);
}
