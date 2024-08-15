/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:55:27 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/15 21:06:12 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include <stdbool.h>

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

typedef struct s_data
{
	t_map	map;
	int		value;
}	t_data;

#endif
