/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 12:12:28 by fharing           #+#    #+#             */
/*   Updated: 2021/12/14 12:12:32 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_free(t_vars *data)
{
	int	i;

	i = 0;
	free(data->north);
	free(data->south);
	free(data->east);
	free(data->west);
	free(data->floor);
	free(data->ceilling);
	free(data->calc);
	free(data->key);
	free(data->sprite);
	free(data->minimap);
	while (i < 9)
	{
		free(data->tex->texture[i]);
		i++;
	}
	free(data->tex->texture);
	mlx_destroy_image(data->mlx, data->img);
	mlx_destroy_window(data->mlx, data->win);
	free(data->mlx);
	free(data->tex);
	free(data);
	exit (1);
}
