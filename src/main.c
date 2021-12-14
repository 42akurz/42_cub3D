/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fharing <fharing@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:35:12 by akurz             #+#    #+#             */
/*   Updated: 2021/12/14 13:29:29 by fharing          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub.h"

int	main(int argc, char **argv)
{
	char		*input;
	char		**parsing;
	t_vars		*data;

	if (argc != 2)
		ft_error(0);
	input = ft_readmap(argv[1]);
	if (input == NULL)
		ft_error(1);
	parsing = ft_split(input, '\n');
	if (parsing == NULL)
		ft_error(2);
	free(input);
	data = ft_init_data_structure(parsing);
	ft_mlx_init(data);
	ft_game_start(data);
	ft_free (data);
	ft_free_strlist(parsing);
	return (0);
}
