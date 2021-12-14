/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 09:47:07 by fharing           #+#    #+#             */
/*   Updated: 2021/06/23 09:48:27 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*re;
	size_t	i;
	size_t	x;

	i = start;
	x = 0;
	if (s == NULL)
		return (NULL);
	re = (char *)malloc(len + 1);
	if (re == NULL)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		re[0] = 0;
		return (re);
	}
	while (s[i] != '\0' && x < len)
	{
		re[x] = s[i];
		x++;
		i++;
	}
	re[x] = '\0';
	return (re);
}
