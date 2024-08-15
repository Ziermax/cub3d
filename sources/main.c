#include "../Libft/includes/libft.h"
#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (fd_printf(2, "Wrong number of arguments\n"), 1);
	fd_printf(1, "Estarting CubTresD\n");
	data.value = argv[1][0];
	fd_printf(1, "Finished Cub2d\n");
	return (data.value);
}
