/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:21:17 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/30 21:36:40 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/cub3d.h"
#include "../includes/structs.h"
#include "../Libft/includes/libft.h"
#include "../includes/color.h"
#include <stdlib.h>
//#include <stdio.h>

char	**maping(void)
{
	char	**layout;

	layout = NULL;
	layout = add_dir(layout, "11111");
	if (!layout)
		return (NULL);
	layout = add_dir(layout, "10001");
	if (!layout)
		return (NULL);
	layout = add_dir(layout, "100S1");
	if (!layout)
		return (NULL);
	layout = add_dir(layout, "10001");
	if (!layout)
		return (NULL);
	layout = add_dir(layout, "11111");
	if (!layout)
		return (NULL);
	return (layout);
}

	//map->ceiling = 0xC95200;
void	map_init(t_map *map)
{
	map->layout = maping();
	if (!map->layout)
		return ;
	map->ceiling = 0xD0FF;
	map->ceiling_low = proportional_color(44 * COLOR_DEF / 100,
			0x0, map->ceiling);
	map->floor = 0xFF00;
	map->floor_low = proportional_color(44 * COLOR_DEF / 100,
			0x0, map->floor);
	map->player.x = 3;
	map->player.y = 2;
	map->player.ang = 0;
}

void	ft_mlx_init(t_mlx *mlx, t_img *img)
{
	mlx->img = NULL;
	mlx->ptr = mlx_init();
	if (!mlx->ptr)
		return ;
	mlx->win = mlx_new_window(mlx->ptr, LENGTH, HEIGTH, "cub3d");
	if (!mlx->win)
		return (free(mlx->ptr));
	img->ptr = mlx_new_image(mlx->ptr, LENGTH, HEIGTH);
	if (!img->ptr)
		return ((void)mlx_destroy_window(mlx->ptr, mlx->win), free(mlx->ptr));
	img->addr = mlx_get_data_addr(img->ptr, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	mlx->img = img;
}

void	data_init(t_data *data, t_mlx *mlx, t_img *img, t_map *map)
{
	data->mlx = NULL;
	ft_mlx_init(mlx, img);
	if (!mlx->img)
		return ;
	map_init(map);
	if (!map->layout)
		return ;
	data->mlx = mlx;
	data->map = map;
	mlx_hook(mlx->win, 2, 1L, key_event, data);
	mlx_hook(mlx->win, 17, 0L, destroy_event, data);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move_event, data);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_click_event, data);
}
//	mlx_mouse_hook(mlx->win, mouse_click_event, data);
