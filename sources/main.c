/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:47:23 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/14 18:15:44 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../Libft/includes/libft.h"
#include "../includes/cub3d.h"
#include "../includes/parser.h"
#include <math.h>

int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc == 2)
	{
		//pon un error si un pelotudo te pasa un .cub a secas
		if (check_file(argv[1]) == -1)
			exit(fd_printf(2, "Error\nWrong file!\nOnly .cub please :)\nPS: We don't accept occulted files uwu\n"));
		if (open_file(argv[1], &fd) == -1)
			exit(fd_printf(2, "Error\nCouldn't open file :(\n Check if the path is correct and file has read permissions\n"));
		close(fd);
	}
	else
	{
		printf("Error\nWrong number of arguments\n");
		exit(1);
	}
}
