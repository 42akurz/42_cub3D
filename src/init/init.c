/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:28 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 10:12:10 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

t_key	*ft_init_key(t_vars *data)
{
	t_key	*key;

	key = malloc(sizeof(t_key));
	key->arrowLeftFlag = false;
	key->arrowRightFlag = false;
	key->upFlag = false;
	key->downFlag = false;
	key->rightFlag = false;
	key->leftFlag = false;
	key->door = false;
	key->sprint = false;
	data->key = key;
	return (key);
}

t_sprite	*ft_init_sprite(t_vars *data)
{
	t_sprite	*sprite;

	sprite = malloc(sizeof(t_sprite));
	data->sprite = sprite;
	return (sprite);
}

t_tex	*ft_init_texture(t_vars *data)
{
	t_tex	*tex;
	int		i;

	tex = ft_calloc(sizeof(t_tex), 1);
	if (tex == NULL)
		return (NULL);
	tex->texture = (int **)malloc(sizeof(int *) * 9);
	if (tex->texture == NULL)
		return (NULL);
	i = 0;
	while (i < 9)
	{
		tex->texture[i] = (int *)ft_calloc(sizeof(int) * (64 * 64), 1);
		if (tex->texture[i] == NULL)
			return (NULL);
		i++;
	}
	data->tex = tex;
	return (tex);
}

void	ft_init_minimap(t_vars *data)
{
	t_minimap	*minimap;

	minimap = malloc(sizeof(t_minimap));
	minimap->a = 0;
	minimap->b = 0;
	minimap->pa = 0;
	minimap->pb = 0;
	minimap->o = 0;
	minimap->u = 0;
	data->minimap = minimap;
}

t_vars	*ft_get_vars(char **data)
{
	t_vars	*re;

	if (ft_getsize_array(data) < 9)
		ft_error(3);
	re = malloc(sizeof(t_vars));
	re->global_count = 0;
	re->spellNumber = 3;
	re->win_width = 1680.00;
	re->win_height = 1200.00;
	ft_init_location(re);
	ft_get_location(re, data);
	ft_check_location(re);
	re->map = &data[6];
	ft_validate_map(re->map);
	if (ft_getsize_array(re->map) >= (re->win_height - 1) / 7)
		ft_error(8);
	if (ft_get_length_map(re->map) >= (re->win_width - 1) / 7)
		ft_error(8);
	re->spelltaken = false;
	return (re);
}
