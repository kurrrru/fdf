/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 20:24:34 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/25 14:59:43 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	// t_data	data;
	t_map	*map;

	param_check(argc, argv);
	map = map_init();
	parse_file(argv[1], map);
	free_map(map);
	return (EXIT_SUCCESS);
}
