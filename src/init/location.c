/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   location.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:33:35 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 11:32:16 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_get_location(t_vars *re, char **data)
{
	int	i;

	i = 0;
	while (data[i])
	{
		if (ft_strnstr(data[i], "NO", 2) != NULL)
			re->north = ft_strdup(data[i] + 3);
		else if (ft_strnstr(data[i], "SO", 2) != NULL)
			re->south = ft_strdup(data[i] + 3);
		else if (ft_strnstr(data[i], "WE", 2) != NULL)
			re->west = ft_strdup(data[i] + 3);
		else if (ft_strnstr(data[i], "EA", 2) != NULL)
			re->east = ft_strdup(data[i] + 3);
		else if (ft_strnstr(data[i], "F", 1) != NULL)
			re->floor = ft_strdup(data[i] + 2);
		else if (ft_strnstr(data[i], "C", 1) != NULL)
			re->ceilling = ft_strdup(data[i] + 2);
		i++;
	}
}

void	ft_init_location(t_vars *re)
{
	re->north = NULL;
	re->south = NULL;
	re->west = NULL;
	re->east = NULL;
	re->floor = NULL;
	re->ceilling = NULL;
}

void	ft_check_location(t_vars *re)
{
	if (re->north == NULL || re->south == NULL || re->west == NULL
		|| re->east == NULL || re->floor == NULL || re->ceilling == NULL)
		ft_error(9);
}
