/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:07:39 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:04:29 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/structs.h"

float	distance_of_points(float xi, float yi, float xf, float yf)
{
	float	dx;
	float	dy;
	float	distance;

	dx = xf - xi;
	dy = yf - yi;
	distance = sqrt((dx * dx) + (dy * dy));
	return (distance);
}

float	distance_to_screen(float hypotenuse, int ang_ray, int ang_player)
{
	float	radian_ray;
	float	radian_player;
	float	distance;

	ang_ray = (ang_ray % (360 * ANG_PRES) + 360 * ANG_PRES) % (360 * ANG_PRES);
	radian_ray = (float)ang_ray / ANG_PRES * M_PI / 180;
	ang_player = (ang_player % (360 * ANG_PRES) + 360 * ANG_PRES)
		% (360 * ANG_PRES);
	radian_player = (float)ang_player / ANG_PRES * M_PI / 180;
	distance = hypotenuse * cos(radian_ray - radian_player);
	if (distance < 0)
		return (-distance);
	return (distance);
}
	//radian_player = (float)ang_player / ANG_PRES * M_PI / 180 + M_PI_2;
	//distance = hypotenuse * sin(radian_ray - radian_player);

int	height_by_distance(float distance)
{
	static float	angle = (float)(FOV_V % 360) *M_PI / 180.f / 2.f;
	float			k;
	int				height;

	k = tan(angle) * 400.f / PX_THCKNSS;
	height = k / (distance * tan(angle));
	return (height);
}

t_eline	get_line_equation(float pos_x, float pos_y, int angle)
{
	t_eline	line;
	float	radian;

	angle = (angle % (360 * ANG_PRES) + 360 * ANG_PRES) % (360 * ANG_PRES);
	if (angle > 90 * ANG_PRES && angle < 270 * ANG_PRES)
		line.direction[X] = -1;
	else if (angle == 90 * ANG_PRES || angle == 270 * ANG_PRES)
		line.direction[X] = 0;
	else
		line.direction[X] = 1;
	if (angle > 0 && angle < 180 * ANG_PRES)
		line.direction[Y] = -1;
	else if (angle == 0 || angle == 180 * ANG_PRES)
		line.direction[Y] = 0;
	else
		line.direction[Y] = 1;
	line.point[X] = pos_x;
	line.point[Y] = pos_y;
	radian = (float)angle / ANG_PRES * M_PI / 180;
	line.slope = -tan(radian);
	line.intercept = line.point[Y] - line.slope * line.point[X];
	return (line);
}
