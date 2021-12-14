/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:35:02 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:35:03 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

int	ft_getsize_array(char **data)
{
	int	i;

	i = 0;
	while (data[i])
		i++;
	return (i);
}

int	ft_get_length_map(char **map)
{
	int	i;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	while (map[i])
	{
		tmp = ft_strlen(map[i]);
		if (tmp > max)
			max = tmp;
		i++;
	}
	return (max);
}

int	ft_check_surrounded(char **map, int i, int x)
{
	if (ft_isspace(map[i][x + 1]) == 0
		&& ft_isspace (map[i][x - 1]) == 0
		&& ft_isspace(map[i + 1][x]) == 0
		&& ft_isspace(map[i - 1][x]) == 0
		&& ft_isspace(map[i + 1][x + 1]) == 0
		&& ft_isspace(map[i + 1][x - 1]) == 0
		&& ft_isspace(map[i - 1][x + 1]) == 0
		&& ft_isspace(map[i - 1][x - 1]) == 0)
		return (1);
	return (0);
}

void	ft_check_closed_walls(char **map)
{
	int	i;
	int	x;
	int	save;

	i = 0;
	save = 0;
	while (map[i])
	{
		if ((int)ft_strlen(map[i]) - 1 < save)
			ft_error(10);
		x = 0;
		save = 0;
		while (map[i][x])
		{
			if (map[i][x] == '0')
			{
				if (ft_check_surrounded(map, i, x) == 0)
					ft_error(10);
				save = x;
			}
			x++;
		}
		i++;
	}
}

void	ft_validate_map(char **map)
{
	int	i;
	int	length;

	i = 1;
	length = ft_getsize_array(map);
	ft_row_check(map[0]);
	ft_row_check(map[length - 1]);
	while (i < length - 1)
	{
		ft_middle_row_check(map[i]);
		i++;
	}
	ft_check_closed_walls(map);
	ft_character_check(map);
	ft_player_check(map);
	ft_potion_check(map);
}
