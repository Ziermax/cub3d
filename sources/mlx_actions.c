/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_actions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 13:16:54 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 17:43:41 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/structs.h"
#include "../includes/keyboard.h"
#include "../minilibx/mlx.h"

void	switch_mouse_state(t_data *data, int state)
{
	if (!state)
	{
		data->mouse_on = 0;
		mlx_mouse_show(data->mlx->ptr, data->mlx->win);
	}
	else
	{
		data->mouse_on = 1;
		mlx_mouse_hide(data->mlx->ptr, data->mlx->win);
	}
}

static void	move_player(t_map *map, float *movement)
{
	float	x;
	float	y;

	x = map->player.x + movement[X];
	y = map->player.y + movement[Y];
	if (x < 0 || x >= map->limits[X] || y < 0 || y >= map->limits[Y])
	{
		map->player.x = (float)map->limits[X] / 2;
		map->player.y = (float)map->limits[Y] / 2;
		map->player.ang = 0;
		return ;
	}
	if (map->layout[(int)map->player.y][(int)x] != '1')
		map->player.x = x;
	if (map->layout[(int)y][(int)map->player.x] != '1')
		map->player.y = y;
}

void	player_movement(int keycode, t_data *data)
{
	float	radian[2];
	float	displacment[2][2];
	float	*movement;

	radian[X] = (float)data->map->player.ang / ANG_PRES * M_PI / 180;
	radian[Y] = radian[X] + M_PI_2;
	displacment[X][X] = cos(radian[X]) * 0.05f;
	displacment[X][Y] = -sin(radian[X]) * 0.05f;
	displacment[Y][X] = cos(radian[Y]) * 0.05f;
	displacment[Y][Y] = -sin(radian[Y]) * 0.05f;
	if (keycode == KEY_W || keycode == KEY_S)
		movement = displacment[X];
	else
		movement = displacment[Y];
	if (keycode == KEY_S)
	{
		displacment[X][X] = -displacment[X][X];
		displacment[X][Y] = -displacment[X][Y];
	}
	else if (keycode == KEY_A)
	{
		displacment[Y][X] = -displacment[Y][X];
		displacment[Y][Y] = -displacment[Y][Y];
	}
	move_player(data->map, movement);
}

void	player_angle_key(int keycode, t_data *data)
{
	if (keycode == KEY_RIGHT)
		data->map->player.ang += 5000;
	else if (keycode == KEY_LEFT)
		data->map->player.ang -= 5000;
}
