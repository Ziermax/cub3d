/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/28 16:47:23 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/01 15:08:26 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx/mlx.h"
#include "../Libft/includes/libft.h"
#include "../includes/cub3d.h"
#include <math.h>

int	open_file(char *argv, int *fd)
{
	if (access(argv, R_OK) == -1)
		return (-1);
	*fd = open(argv, O_RDONLY);
	return (*fd);
}

int	file_is_ocult(char *argv)
{
	//int		i;
	char	*checker;

	checker = ft_strrchr(argv, '/');
	if (checker && ft_strncmp(checker + 1, ".", 1) == 0)
		return (-1);
	if (!checker && ft_strncmp(argv, ".", 1) == 0)
		return (-1);
	return (0);
}

int	check_file(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 4;
	if (i > 0)
	{
		if (file_is_ocult(argv) == 0 && ft_strncmp(argv + i, ".cub", 4) == 0)
			return (0);
	}
	return (-1);
}

int	main(int argc, char **argv)
{
	int	fd;
	
	if (argc == 2)
	{
		//pon un error si un pelotudo te pasa un .cub a secas
		if (check_file(argv[1]) == -1)
			exit(fd_printf(2, "Error\nWrong file!\nOnly .cub please :)\nPS: We don't accept occulted files uwu\n"));
		if (open_file(argv[1], &fd) == -1))
			exit(fd_printf(2, "Error\nCouldn't open file :(\n Check if the path is correct and file has read permissions\n");
		
	}
	else
	{
		printf("Error\nWrong number of arguments\n");
		exit(1);
	}
}
