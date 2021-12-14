/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 09:00:57 by fharing           #+#    #+#             */
/*   Updated: 2021/06/18 12:00:13 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	x;

	i = 0;
	if (ft_strlen(little) == 0)
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		x = 0;
		while (little[x] == big[i + x] && i + x < len)
		{
			if (little[x + 1] == '\0')
				return ((char *)(big + i));
			x++;
		}
		i++;
	}
	return (0);
}
