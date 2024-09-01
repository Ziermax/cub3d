/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:43 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/31 13:18:22 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"

void	split_image(t_mlx *mlx, t_map *map);
/*	mlx functions related	*/
void	data_init(t_data *data, t_mlx *mlx, t_img *img, t_map *map);
int		destroy_event(t_data *data);
int		key_event(int keycode, t_data *data);
int		mouse_click_event(int keycode, int x_m, int y_m, t_data *data);
int		mouse_move_event(int x, int y, t_data *data);
void	draw_pixel(int x, int y, int color, t_mlx *mlx);
void	draw_column(int x, int heigth, int color, t_mlx *mlx);
int		height_by_distance(float distance);

#endif
