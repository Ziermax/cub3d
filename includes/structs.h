/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:55:27 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/14 17:25:49 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define LENGTH 1920
# define HEIGTH 1080
# define X 0
# define Y 1
# define PX_THCKNSS 1
# define FOV_V 60
# define FOV 50
# define ANG_PRES 1000

// Y = m * X + n
// Y = slope * X + intercept;

typedef struct s_plyer
{
	float	x;
	float	y;
	int		ang;
	int		*fov;
	int		fov_angles;
}	t_plyer;

typedef struct s_map
{
	char	**layout;
	void	*img_north;
	void	*img_south;
	void	*img_west;
	void	*img_east;
	int		limits[2];
	int		ceiling;
	int		ceiling_low;
	int		floor;
	int		floor_low;
	t_plyer	player;
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
	int		mouse_on;
}	t_data;

typedef struct s_eline
{
	float	slope;
	float	intercept;
	float	point[2];
	float	direction[2];
}	t_eline;

typedef struct s_ray_casting
{
	int		position[2];
	int		direction[2];
	int		barrier;
	float	cut;
	t_eline	ray;
	t_map	*map;
}	t_ray_casting;

typedef struct s_column
{
	float	distance;
	float	point[2];
	int		map[2];
	int		x;
	int		height;
	void	*sprite;
}	t_column;

void	delete_map(void *map);
void	delete_mlx(void *mlx);

#endif
