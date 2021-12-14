/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 10:01:05 by fharing           #+#    #+#             */
/*   Updated: 2021/06/18 15:06:34 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*re;
	int		i;
	int		x;

	i = 0;
	x = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	re = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (re == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		re[i] = s1[i];
		i++;
	}
	while (s2[x] != '\0')
		re[i++] = s2[x++];
	re[i] = '\0';
	return (re);
}
