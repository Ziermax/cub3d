/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:10:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:06:05 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

# include "structs.h"

# define COLOR_DEF 500

int		proportional_color(int percentage, int min_color, int max_color);
void	draw_pixel(int x, int y, int color, t_mlx *mlx);
void	draw_column(int x, int heigth, int color, t_mlx *mlx);
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	split_image(t_mlx *mlx, t_map *map);

#endif
