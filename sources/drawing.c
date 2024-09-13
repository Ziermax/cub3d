/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:54:45 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:00:25 by mvelazqu         ###   ########.fr       */
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

void	draw_column(int x, int heigth, int color, t_mlx *mlx)
{
	int	column;
	int	half_screen;

	if (heigth <= 0 || x < 0 || x * PX_THCKNSS > LENGTH + PX_THCKNSS)
		return ;
	half_screen = HEIGTH / PX_THCKNSS / 2;
	if ((long)heigth * 2 * PX_THCKNSS > (long)HEIGTH + PX_THCKNSS)
		heigth = HEIGTH / PX_THCKNSS / 2 + 2;
	draw_pixel(x, half_screen, color, mlx);
	column = 1;
	while (column < heigth)
	{
		draw_pixel(x, half_screen + column, color, mlx);
		draw_pixel(x, half_screen - column, color, mlx);
		column++;
	}
}
