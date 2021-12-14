/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akurz <akurz@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:35:07 by akurz             #+#    #+#             */
/*   Updated: 2021/12/13 19:35:08 by akurz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_row_check(char *s)
{
	int	i;

	i = 0;
	while (ft_isspace(s[i]))
		i++;
	while (s[i])
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i] == 0)
			break ;
		if (s[i] != '1')
			ft_error(5);
		i++;
	}
}

void	ft_middle_row_check(char *s)
{
	int	i;
	int	x;

	x = ft_strlen(s) - 1;
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	if (s[i] != '1' || s[ft_strlen(s) - 1] != '1')
		ft_error(5);
}

void	ft_character_check(char **map)
{
	int		i;
	int		x;
	char	*allowed_chars;

	i = 0;
	allowed_chars = ft_strdup("012NESW4 \n\t\v\f\r");
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (ft_strchr(allowed_chars, map[i][x]) == NULL)
			{
				free (allowed_chars);
				ft_error(5);
			}
			x++;
		}
		i++;
	}
	free (allowed_chars);
}

void	ft_player_check(char **map)
{
	int		i;
	int		x;
	int		c;
	char	*allowed_chars;

	i = 0;
	c = 0;
	allowed_chars = ft_strdup("NESW");
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (ft_strchr(allowed_chars, map[i][x]) != NULL)
				c++;
			x++;
		}
		i++;
	}
	if (c != 1)
	{
		free (allowed_chars);
		ft_error(5);
	}
	free (allowed_chars);
}

void	ft_potion_check(char **map)
{
	int		i;
	int		x;
	int		c;

	i = 0;
	c = 0;
	while (map[i])
	{
		x = 0;
		while (map[i][x])
		{
			if (map[i][x] == '4')
				c++;
			x++;
		}
		i++;
	}
	if (c > 1)
		ft_error(7);
}
