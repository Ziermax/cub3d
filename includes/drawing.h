/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/30 20:10:22 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/30 20:10:58 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAWING_H
# define DRAWING_H

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
void	split_image(t_mlx *mlx, t_map *map);

#endif
