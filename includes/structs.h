/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:55:27 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/28 20:11:13 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define LENGTH 1920
# define HEIGTH 1080

typedef struct s_map
{
	char	**layout;
	void	*img_north;
	void	*img_south;
	void	*img_west;
	void	*img_east;
	void	*ceiling;
	void	*floor;
	int		player[2];
}	t_map;

typedef struct s_img
{
	void	*ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	t_img	*img;
}	t_mlx;

typedef struct s_data
{
	t_map	*map;
	t_mlx	*mlx;
	int		value;
}	t_data;

#endif
