/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_main_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkawaguc <nkawaguc@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:21:02 by nkawaguc          #+#    #+#             */
/*   Updated: 2024/10/29 23:07:38 by nkawaguc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "b_fdf_bonus.h"

int	main(int argc, char **argv)
{
	int		ret;
	t_map	*map;

	ret = param_check(argc, argv);
	if (ret == STL_FLAG)
	{
		stl(argv[1]);
	}
	else
	{
		map = map_init();
		parse_file(argv[1], map);
		fdf(map);
		free_map(map);
	}
	return (EXIT_SUCCESS);
}
