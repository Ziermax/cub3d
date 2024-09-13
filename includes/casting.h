/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 14:08:29 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/13 18:04:20 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CASTING_H
# define CASTING_H

# include "../includes/structs.h"

float	distance_of_points(float xi, float yi, float xf, float yf);
int		height_by_distance(float distance);
float	distance_to_screen(float hypotenuse, int ang_ray, int ang_player);
t_eline	get_line_equation(float pos_x, float pos_y, int angle);

#endif
