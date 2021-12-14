/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:44:47 by fharing           #+#    #+#             */
/*   Updated: 2021/12/14 13:39:46 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_error(int i)
{
	if (i == 0)
		printf("Help:\n./cub3D MAPNAME (./cub3D map.cub)\n");
	if (i == 1)
		printf("Error\nCan't find map!\n");
	if (i == 2)
		printf("Error\nCan't parse map(memory)!\n");
	if (i == 3)
		printf("Error\nFound wrong length in mapfile!\n");
	if (i == 4)
		printf("Error\nWrong RGB code!\n");
	if (i == 5)
		printf("Error\nMap error encounterd!\n");
	if (i == 6)
		printf("Error\nPicture not found!\n");
	if (i == 7)
		printf("Error\nOnly one potion allowed!\n");
	if (i == 8)
		printf("Error\nMap to big!\n");
	if (i == 9)
		printf("Error\nMissing information(N/E/S/W/Floor/Ceiling)!\n");
	if (i == 10)
		printf("Error\nMap not surrounded by walls!\n");
	if (i == 11)
		printf("Error\nMemory allocation failed!\n");
	exit(1);
}
