/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:21:17 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/28 20:12:23 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx.h"
#include "../includes/cub3d.h"
#include "../includes/structs.h"
#include "../Libft/includes/libft.h"
#include <stdlib.h>

void	data_init(t_data *data, t_mlx *mlx, t_img *img, t_map *map)
{
	ft_bzero(data, sizeof(t_data));
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
	data->mlx = mlx;
	data->map = map;
	mlx_hook(mlx->win, 2, 1L, key_event, data);
	mlx_hook(mlx->win, 17, 0L, destroy_event, data);
	mlx_hook(mlx->win, 6, 1L << 6, mouse_move_event, data);
	mlx_hook(mlx->win, 4, 1L << 2, mouse_click_event, data);
}
//	mlx_mouse_hook(mlx->win, mouse_click_event, data);
