/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:11:33 by fharing           #+#    #+#             */
/*   Updated: 2021/06/18 09:39:45 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void	*a;
	char	*b;
	size_t	i;

	i = 0;
	b = (char *)malloc(nitems * size);
	if (b == NULL)
		return (NULL);
	while (i < nitems * size)
	{
		b[i] = 0;
		i++;
	}
	a = (void *)b;
	return (a);
}
