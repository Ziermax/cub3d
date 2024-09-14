/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvelazqu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 18:12:05 by mvelazqu          #+#    #+#             */
/*   Updated: 2024/09/14 18:16:47 by mvelazqu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <unistd.h>
# include <fcntl.h>
#include "../Libft/includes/libft.h"

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
