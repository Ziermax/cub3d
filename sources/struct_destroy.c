/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 15:54:55 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/08/31 01:51:26 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../minilibx/mlx.h"
#include "../includes/structs.h"

void	delete_mlx(void *mlx)
{
	t_mlx	*aux;

	if (!mlx)
		return ;
	aux = mlx;
	mlx_destroy_image(aux->ptr, aux->img->ptr);
	mlx_destroy_window(aux->ptr, aux->win);
	mlx_destroy_display(aux->ptr);
	free(aux->ptr);
}

void	delete_map(void *map)
{
	t_map	*aux;

	if (!map)
		return ;
	aux = map;
	free(aux->layout);
	free(aux->player.fov);
}
