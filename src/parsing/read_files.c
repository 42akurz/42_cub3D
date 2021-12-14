/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:34:56 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 12:19:29 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub.h"

char	*ft_read_loop(int bytesred, char buff[2], int fd)
{
	char	*tmp;
	char	*str;

	str = NULL;
	while (bytesred > 0)
	{
		buff[bytesred] = '\0';
		if (str == NULL)
			str = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str, buff);
			free (str);
			str = tmp;
		}
		bytesred = read(fd, buff, 1);
	}
	return (str);
}

char	*ft_readmap(char *file)
{
	char	*str;
	int		fd;
	char	buff[2];
	int		bytesred;
	int		length;

	length = ft_strlen(file);
	if (length < 5)
		ft_error(0);
	if (file[length - 4] != '.' && file[length - 3] != 'c'
		&& file[length - 2] != 'u' && file[length - 1] != 'b')
		ft_error(0);
	str = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	bytesred = read(fd, buff, 1);
	if (bytesred > 0)
		str = ft_read_loop(bytesred, buff, fd);
	if (close(fd) == -1)
		return (0);
	return (str);
}
