/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:54:45 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/15 02:19:46 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../Libft/includes/libft.h"
#include "../includes/drawing.h"

void	draw_pixel(int x, int y, int color, t_mlx *mlx)
{
	int	thck[2];
	int	px[2];

	if (y < 0 || x < 0 || x * PX_THCKNSS >= LENGTH || y * PX_THCKNSS >= HEIGTH)
		return ;
	x *= PX_THCKNSS;
	y *= PX_THCKNSS;
	thck[X] = 0;
	while (thck[X] < PX_THCKNSS)
	{
		thck[Y] = 0;
		while (thck[Y] < PX_THCKNSS)
		{
			px[X] = x + thck[X];
			px[Y] = y + thck[Y];
			if (px[X] >= 0 && px[X] < LENGTH && px[Y] >= 0 && px[Y] < HEIGTH)
				my_mlx_pixel_put(mlx->img, x + thck[X], y + thck[Y], color);
			thck[Y]++;
		}
		thck[X]++;
	}
}

int	get_x_from_column(t_column column, t_img sprite)
{
	float	proportion;
	int		x;

	if (column.point[X] == (float)column.map[X]
		|| column.point[X] == (float)(column.map[X] + 1))
		proportion = column.point[Y] - column.map[Y];
	else
		proportion = column.point[X] - column.map[X];
	x = proportion * sprite.width;
	return (x);
}

int	get_color_from_column(t_column column, t_img sprite, int base)
{
	int	color;
	int	full_height;
	int	y;

	full_height = 2 * column.height;
	y = (float)(column.height - base) / full_height * sprite.height;
	color = my_mlx_get_pixel_color(&sprite, column.x, y);
	return (color);
}

void	draw_column(t_column column, t_mlx *mlx)
{
	int	x;
	int	base;
	int	color;
	int	half_screen;
	int	stop_height;

	x = column.x;
	column.x = get_x_from_column(column, column.sprite);
	if (column.height <= 0 || x < 0 || x * PX_THCKNSS > LENGTH + PX_THCKNSS)
		return ;
	half_screen = HEIGTH / PX_THCKNSS / 2;
	stop_height = column.height;
	if ((long)column.height * 2 * PX_THCKNSS > (long)HEIGTH + PX_THCKNSS)
		stop_height = HEIGTH / PX_THCKNSS / 2 + 2;
	color = get_color_from_column(column, column.sprite, 0);
	draw_pixel(x, half_screen, color, mlx);
	base = 1;
	while (base < stop_height)
	{
		color = get_color_from_column(column, column.sprite, base);
		draw_pixel(x, half_screen + base, color, mlx);
		color = get_color_from_column(column, column.sprite, -base);
		draw_pixel(x, half_screen - base, color, mlx);
		base++;
	}
}
