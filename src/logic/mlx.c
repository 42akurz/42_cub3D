/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:22 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 14:03:26 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	logic(t_vars *vars)
{
	int	x;

	x = 0;
	ft_movement(vars);
	while (x < (int)vars->win_width)
	{
		ft_rayPosition_and_Direction(vars, x);
		ft_step_and_sideDistance(vars);
		ft_DDA_algorithm(vars);
		ft_drawStart_and_drawEnd(vars);
		ft_draw_texture(vars, x);
		ft_floor_ceilling(vars, x);
		vars->sprite->ZBuffer[x] = vars->calc->perpWallDist;
		x++;
	}
	if (vars->spelltaken == false)
		ft_draw_sprite(vars);
	if (ft_isdoor(vars) == 1)
		vars->map[vars->calc->mapX][vars->calc->mapY] = '3';
	if (ft_validate_distance_to_door(vars) == 2)
		ft_isdoor_open(vars);
	draw(vars);
	ft_sprite_animation(vars);
	return (1);
}

void	ft_mlx_init(t_vars *data)
{
	data->mlx = mlx_init();
	load_texture(data);
	data->win = mlx_new_window(data->mlx, data->win_width,
			data->win_height, "CUB3D");
	data->calc->frameTime = (16) / 1000.0;
	data->calc->moveSpeed = data->calc->frameTime * 5.0;
	data->calc->rotSpeed = data->calc->frameTime * 3.0;
	data->img = mlx_new_image(data->mlx, data->win_width, data->win_width);
	data->addr = (int *)mlx_get_data_addr(data->img, &data->bits_per_pixel,
			&data->line_length, &data->endian);
}

t_vars	*ft_init_data_structure(char **parsing)
{
	t_vars	*data;

	data = ft_get_vars(parsing);
	if (data == NULL)
		ft_error(11);
	data->calc = ft_init_calc(data);
	if (data->calc == NULL)
		ft_error(11);
	data->key = ft_init_key(data);
	if (data->key == NULL)
		ft_error(11);
	data->sprite = ft_init_sprite(data);
	if (data->sprite == NULL)
		ft_error(11);
	data->tex = ft_init_texture(data);
	if (data->tex == NULL)
		ft_error(11);
	ft_init_minimap(data);
	if (data->minimap == NULL)
		ft_error(11);
	ft_get_colour_code(data->floor, &data->floorcode);
	ft_get_colour_code(data->ceilling, &data->ceillingcode);
	return (data);
}

void	ft_game_start(t_vars *data)
{
	mlx_mouse_hide(data);
	mlx_mouse_move(data->win, data->win_width / 2, data->win_height / 2 );
	mlx_do_key_autorepeatoff(data->mlx);
	mlx_hook(data->win, 17, (1L << 17), close_window, &data);
	mlx_hook(data->win, 2, (1L << 0), &set_keyFlag_true, data);
	mlx_hook(data->win, 3, (1L << 1), &set_keyFlag_false, data);
	mlx_loop_hook(data->mlx, logic, data);
	mlx_loop(data->mlx);
}
