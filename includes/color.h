/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 19:26:05 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/30 23:33:29 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# include "structs.h"

# define COLOR_DEF 500

int		proportional_color(int percentage, int min_color, int max_color);
void	draw_pixel(int x, int y, int color, t_mlx *mlx);

#endif
