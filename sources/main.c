/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:47:23 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:01:36 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../Libft/includes/libft.h"
#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;
	t_mlx	mlx;
	t_img	img;
	t_map	map;

	(void)argv;
	if (argc == 2)
		return (fd_printf(2, "Wrong number of arguments\n"), 1);
	fd_printf(1, "Estarting CubTresD\n");
	data_init(&data, &mlx, &img, &map);
	if (!data.mlx)
		return (fd_printf(2, "Failed mlx_functions\n"));
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img->ptr, 0, 0);
	fd_printf(1, "Finished Cub2d\n");
	mlx_loop(data.mlx->ptr);
	return (0);
}
