/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 16:27:09 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:02:52 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "../includes/casting.h"

static t_column	intersection_column_x(t_eline line, int *range, char **map)
{
	t_column	column;
	int			barrier;
	float		cut;

	column.distance = range[X] + range[Y];
	if (!line.direction[X])
		return (column);
	column.map[X] = (int)line.point[X] + line.direction[X];
	while (column.map[X] >= 0 && column.map[X] < range[X])
	{
		barrier = column.map[X] + (line.direction[X] < 0);
		cut = line.slope * (float)barrier + line.intercept;
		if (cut < 0 || cut >= range[Y])
			return (column);
		if (map[(int)cut][column.map[X]] == '1')
			break ;
		column.map[X] += line.direction[X];
	}
	column.map[X] = column.map[X];
	column.map[Y] = (int)cut;
	column.point[X] = (float)barrier;
	column.point[Y] = cut;
	column.distance = distance_of_points(line.point[X], line.point[Y],
			column.point[X], column.point[Y]);
	return (column);
}
//	int			position; Instead of column.map[X]
//			printf("X | Out of range cut(x)\n");
//	printf("X | map(%d, %d) | (%.3f, %.3f)\ndistance: %f | height: %d\n",
//			column.map[X], column.map[Y], column.point[X], column.point[Y],
//			column.distance, column.height);

static t_column	intersection_column_y(t_eline line, int *range, char **map)
{
	t_column	column;
	int			barrier;
	float		cut;

	column.distance = range[X] + range[Y];
	if (!line.direction[Y])
		return (column);
	column.map[Y] = (int)line.point[Y] + line.direction[Y];
	while (column.map[Y] >= 0 && column.map[Y] < range[Y])
	{
		barrier = column.map[Y] + (line.direction[Y] < 0);
		cut = ((float)barrier - line.intercept) / line.slope;
		if (cut < 0 || cut >= range[X])
			return (column);
		if (map[column.map[Y]][(int)cut] == '1')
			break ;
		column.map[Y] += line.direction[Y];
	}
	column.map[X] = (int)cut;
	column.map[Y] = column.map[Y];
	column.point[X] = cut;
	column.point[Y] = (float)barrier;
	column.distance = distance_of_points(line.point[X], line.point[Y],
			column.point[X], column.point[Y]);
	return (column);
}
//	int			position;
//			printf("Y | Out of range cut(x)\n");
//	printf("Y | map(%d, %d) | (%.3f, %.3f)\ndistance: %f | height: %d\n",
//			column.map[X], column.map[Y], column.point[X], column.point[Y],
//			column.distance, column.height);

static void	*get_sprite(int *map, float *point)
{
	if (map[X] == (int)point[X])
	{
		if (map[Y] == (int)point[Y])
			return ((void *)1);
		return ((void *)2);
	}
	if (map[Y] == (int)point[Y])
		return ((void *)3);
	return ((void *)4);
}

t_column	distance_to_wall(t_map *map, int angle)
{
	t_column	column[2];
	t_column	aux;
	t_eline		line;

	angle = (angle % (360 * ANG_PRES) + 360 * ANG_PRES) % (360 * ANG_PRES);
	line = get_line_equation(map->player.x, map->player.y, angle);
	column[X] = intersection_column_x(line, map->limits, map->layout);
	column[Y] = intersection_column_y(line, map->limits, map->layout);
	if (column[X].distance < column[Y].distance)
		aux = column[X];
	else
		aux = column[Y];
	aux.distance = distance_to_screen(aux.distance, angle, map->player.ang);
	aux.height = height_by_distance(aux.distance);
	aux.sprite = get_sprite(aux.map, aux.point);
	return (aux);
}
	//printf("line equation (%.3f, %.3f) ang: %d\n | "
	//	"%.3f = %.3f * %.3f + %.3f\n",
	//	map->player.x, map->player.y, angle,
	//	line.point[Y], line.slope, line.point[X], line.intercept);
	//printf("A | map(%d, %d) | (%.3f, %.3f)\ndistance: %f | height: %d\n",
	//		aux.map[X], aux.map[Y], aux.point[X], aux.point[Y],
	//		aux.distance, aux.height);
