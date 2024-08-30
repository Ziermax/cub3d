/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 16:09:29 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/30 23:32:55 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../includes/structs.h"
#include "../includes/cub3d.h"
#include "../includes/color.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	split_image(t_mlx *mlx, t_map *map)
{
	int	half_img;
	int	color;
	int	x;
	int	y;

	y = 0;
	half_img = HEIGTH / 2;
	while (y * PX_THCKNSS < HEIGTH)
	{
		x = 0;
		if (y * PX_THCKNSS + half_img < HEIGTH)
			color = proportional_color(y * PX_THCKNSS * COLOR_DEF
					/ (HEIGTH - half_img), map->ceiling, map->ceiling_low);
		else
			color = proportional_color((y * PX_THCKNSS - half_img) * COLOR_DEF
					/ (HEIGTH - half_img), map->floor_low, map->floor);
		while (x * PX_THCKNSS < LENGTH)
			draw_pixel(x++, y, color, mlx);
		y++;
	}
}
