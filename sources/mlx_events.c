/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:41:25 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 17:44:05 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../includes/structs.h"
#include "../includes/keyboard.h"
#include "../includes/mlx_event.h"

int	leave_event(t_data *data);

int	destroy_event(t_data *data)
{
	delete_mlx(data->mlx);
	delete_map(data->map);
	exit(0);
}

int	key_event(int keycode, t_data *data)
{
	if (keycode == KEY_ESC)
		return (destroy_event(data));
	if (keycode == KEY_W || keycode == KEY_D
		|| keycode == KEY_A || keycode == KEY_S)
		player_movement(keycode, data);
	else if (keycode == KEY_RIGHT || keycode == KEY_LEFT)
		player_angle_key(keycode, data);
	else if (keycode == KEY_TAB)
		switch_mouse_state(data, 0);
	return (0);
}
//	printf("keycode: %d\n", keycode);

int	mouse_click_event(int keycode, int x, int y, t_data *data)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)data;
	if (keycode == MOUSE_CLICK)
		switch_mouse_state(data, 1);
	return (0);
}
//	printf("keycode: %d\n", keycode);
//	printf("mouse: (x: %d, y: %d)\n", x, y);

int	mouse_move_event(int x, int y, t_data *data)
{
	static int	last_x = LENGTH / 2;

	if (x == -1 || y == -1)
		return (last_x = LENGTH / 2, 0);
	if (!data->mouse_on)
		return (last_x = x, 0);
	data->map->player.ang += 100 * (x - last_x);
	last_x = x;
	return (0);
}
//	if (x == 0 || x == LENGTH || y == 0 || y == HEIGTH)
//		return (leave_event(data));
//	if (x >= LENGTH / 3 || x <= LENGTH * 2 / 3
//		|| y >= HEIGTH / 3 || y <= HEIGTH * 2 / 3)
//		return (leave_event(data));
//	printf("last: %d | now: %d\n", last_x, x);
//	printf("mouse_position: (x: %d, y: %d)\n", x, y);

int	leave_event(t_data *data)
{
	if (!data->mouse_on)
		return (0);
	mlx_mouse_move(data->mlx->ptr, data->mlx->win, LENGTH / 2, HEIGTH / 2);
	mouse_move_event(-1, -1, NULL);
	return (0);
}
