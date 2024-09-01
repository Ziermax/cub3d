/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_events.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 15:41:25 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/29 16:12:59 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../includes/structs.h"
#include "../includes/keyboard.h"
//#include <stdio.h>

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
	return (0);
}
//	printf("keycode: %d\n", keycode);

int	mouse_click_event(int keycode, int x, int y, t_data *data)
{
	(void)keycode;
	(void)x;
	(void)y;
	(void)data;
	return (0);
}
//	printf("keycode: %d\n", keycode);
//	printf("mouse: (x: %d, y: %d)\n", x, y);

int	mouse_move_event(int x, int y, t_data *data)
{
	(void)x;
	(void)y;
	(void)data;
	return (0);
}
//	printf("mouse_position: (x: %d, y: %d)\n", x, y);
