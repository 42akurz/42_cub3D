/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:51 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 12:03:15 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	close_window(void)
{
	exit(0);
}

int	set_keyFlag_false(int keycode, t_vars *vars)
{
	mlx_do_key_autorepeatoff(vars->mlx);
	if (keycode == 1)
		vars->key->downFlag = false;
	if (keycode == 2)
		vars->key->rightFlag = false;
	if (keycode == 0)
		vars->key->leftFlag = false;
	if (keycode == 13)
		vars->key->upFlag = false;
	if (keycode == 124)
		vars->key->arrowLeftFlag = false;
	if (keycode == 123)
		vars->key->arrowRightFlag = false;
	if (keycode == 49)
		vars->key->door = false;
	if (keycode == 14)
		vars->key->doorclose = false;
	if (keycode == 257)
		vars->key->sprint = false;
	return (1);
}

int	set_keyFlag_true(int keycode, t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	if (keycode == 1)
		vars->key->downFlag = true;
	if (keycode == 2)
		vars->key->rightFlag = true;
	if (keycode == 0)
		vars->key->leftFlag = true;
	if (keycode == 13)
		vars->key->upFlag = true;
	if (keycode == 124)
		vars->key->arrowLeftFlag = true;
	if (keycode == 123)
		vars->key->arrowRightFlag = true;
	if (keycode == 49)
		vars->key->door = true;
	if (keycode == 14)
		vars->key->doorclose = true;
	if (keycode == 257)
		vars->key->sprint = true;
	if (keycode == 53)
		close_window();
	return (1);
}
