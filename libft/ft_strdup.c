/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:46:06 by fharing           #+#    #+#             */
/*   Updated: 2021/07/13 15:41:25 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str1)
{
	char	*re;
	size_t	i;

	i = 0;
	re = (char *)ft_calloc(1, ft_strlen(str1) + 1);
	if (re == NULL)
		return (NULL);
	while (str1[i] != '\0')
	{
		re[i] = str1[i];
		i++;
	}
	re[i] = '\0';
	return (re);
}
