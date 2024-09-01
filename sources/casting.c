/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:51:05 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/31 18:14:35 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "../includes/structs.h"
#include <stdio.h>

//float	distance_to_wall(t_map *map, int angle)
//{
//	float	radian;
//	float	distance[2];
//	float	player[2];
//
//	radian = (float)angle / 1000 * M_PI / 360;
//	player[X] = map.player.x;
//	player[Y] = map.player.y;
//	while (map->layout[map.player.y][player[X]])
//	{
//		player[X]++;
//	}
//	return (radian);
//}

int	height_by_distance(float distance)
{
	static float	angle = (float)(FOV_V % 360) * M_PI / 360 / 2;
	int			height;

	height = distance / tan(angle);
	return (height);
}
	//printf("distance: %f | height: %d | ang: %f\n", distance, height, angle);

//float	distance_to_wall(t_map *map, int angle)
//{
//	float	radian;
//
//	radian = (float)angle / 1000 * M_PI / 360;
//}
