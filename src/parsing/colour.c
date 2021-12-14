/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:52 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 12:22:03 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

void	ft_get_colour_code(void *input, long *returncode)
{
	char	**tmp;
	void	*temp;
	int		r;
	int		g;
	int		b;

	temp = input;
	tmp = ft_split(temp, ',');
	if (ft_getsize_array(tmp) != 3)
		ft_error(4);
	r = ft_atoi(tmp[0]);
	g = ft_atoi(tmp[1]);
	b = ft_atoi(tmp[2]);
	if (r < 0 || g < 0 || b < 0 || r > 255 || g > 255 || b > 255)
		ft_error(4);
	*returncode = ((r & 0xff) << 16) | ((g & 0xff) << 8) | (b & 0xff);
	ft_free_strlist(tmp);
}
