/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 11:06:26 by fharing           #+#    #+#             */
/*   Updated: 2021/06/23 10:02:02 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t siz)
{
	size_t	i;
	size_t	x;
	int		re;

	i = ft_strlen(dst);
	re = ft_strlen(src);
	x = 0;
	if (siz <= i)
		return (ft_strlen(src) + siz);
	while (src[x] != '\0' && i < (siz - 1))
	{
		dst[i] = src[x];
		x++;
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(dst) + re - x);
}
