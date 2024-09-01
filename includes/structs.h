/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:55:27 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/01 14:52:37 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

# define LENGTH 1920
# define HEIGTH 1080
# define X 0
# define Y 1
# define PX_THCKNSS 40
# define FOV_V 60
# define FOV 90

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
	int		value;
}	t_data;

void	delete_map(void *map);
void	delete_mlx(void *mlx);

#endif
