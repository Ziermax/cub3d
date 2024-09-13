/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:29:43 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:10:25 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "structs.h"

/*	mlx functions related	*/
void		data_init(t_data *data, t_mlx *mlx, t_img *img, t_map *map);
/*	events	*/
int			destroy_event(t_data *data);
int			key_event(int keycode, t_data *data);
int			mouse_click_event(int keycode, int x_m, int y_m, t_data *data);
int			mouse_move_event(int x, int y, t_data *data);
int			leave_event(t_data *data);
int			render_image(t_data *data);
/*	drawing	*/
t_column	distance_to_wall(t_map *map, int angle);

#endif
