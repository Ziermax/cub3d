#include "../Libft/includes/libft.h"
#include "../includes/structs.h"
#include "../includes/cub3d.h"

int is_valid_char(char c) {
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int	lateral_closed(int player_y, int player_x, char **layout, int limit)
{
	int	i;
	int	j;

	i = player_y;
	j = player_x;
	while(j >= 0 && j < limit)
	{
		layout[i][j] = 'F';
		if (!j)
			return (-1);
		if (layout[i][j - 1] == '1')
			break ;
		j--;
	}

	j = player_x;
	while(j >= 0 && j < limit)
	{
		layout[i][j] = 'F';	
		if (!j)
			return (-1);
		if (layout[i][j + 1] == '1')
			break ;
		j = j + 1;
	}
	return (0);
}

int	is_closed(t_map *map_info)
{
	int	i;
	int	j;

	i = map_info->player.y;
	while (i >= 0 && i < map_info->limits[Y])
	{
		j = map_info->player.x;
		if (!i ||lateral_closed(i, j, map_info->layout, map_info->limits[X]) == -1)
			return (-1);
		if (map_info->layout[i - 1][j] == '1')
			break ;
		i--;
	}
	i = map_info->player.y;
	while (i >= 0 && i < map_info->limits[Y])
	{
		j = map_info->player.x;
		if (!i || lateral_closed(i, j, map_info->layout, map_info->limits[X]) == -1)
			return (-1);
		if (map_info->layout[i + 1][j] == '1')
			break ;
		i++;
	}
	return (0);
}

char	*fill_zeros(int count, int size)
{
	char	*rtrn;
	int		i;

	rtrn = malloc(sizeof(char) * ((count * size) + 1));
	if (!rtrn)
		return (NULL);
	i = 0;
	count = count * size;
	while (i < count)
		rtrn[i++] = '0';
	rtrn[count] = '\0';
	return (rtrn);
}

char	**square_map(char **map, int width)
{
	int		i;
	int 	j;
	char	*new_line;

	i = 0;
	while(map && map[i])
	{
		new_line = fill_zeros(width, sizeof(char));
		if (!new_line)
			return (NULL);
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
				new_line[j] = map[i][j];
			j++;
		}
		free(map[i]);
		map[i] = ft_strdup(new_line);
		if (!map[i])
			return(NULL);
		i++;
	}
	return (map);
}

int validate_map(char **map, int height, t_map *map_info)
{
    int i;
    //int j;
    int width;
    int row_len;

    i = 0;
    width = 0;
    while (i < height)
    {
        row_len = ft_strlen(map[i]);
        if (row_len > width)
            width = row_len;
        i++;
    }
	map = square_map(map, width);
	map_info->limits[X] = width;
	map_info->limits[Y] = height;
	map_info->layout = map;
	is_closed(map_info);
	print_split(map_info->layout);
	return (0);
}

/*
int parse_map(int fd, t_map *map) {
    char **layout;
    char *line;
    int index;
    int player_found;
    //int line_count; a lo mejor la necesito luego
    int map_ended;

    layout = NULL;
    map_ended = 0;
    player_found = 0;
    index = 0;
   
    // leer el archivo y almacenar las líneas en layout
    line = get_next_line(fd);
    while (line)
    {
        if (ft_strlen(line) == 0 && map_ended == 0)
        {
            free(line);  // skip empty lines
            line = get_next_line(fd);
            continue;
        }
        if (ft_strlen(line) == 0 && map_ended == 1) //revisar este error
        {
            printf("Error\n There's an empty line in between.\n");
            return -1;
        }
        layout = (char **)add_dir(layout, line);
        //index = ft_arraylen(layout) - 1;
        // miramos la posición del jugador
        int i = 0;
        while (layout[index][i])
        {
            if (ft_strchr("NSWE", layout[index][i]))
            {
                if (player_found) // si ya teniamos un jugador
                {
                    fd_printf(2, "Error\n Multiple player starting positions found.\n");
                    return (-1);
                }
                player_found = 1;
                map->player.x = i;
                map->player.y = index;
                //Si encontramos el jugador, le pegamos la orientación
                if (layout[index][i] == 'N')
                    map->player.ang = 90 * ANG_PRES;
                else if (layout[index][i] == 'S')
                    map->player.ang = 270 * ANG_PRES;
                else if (layout[index][i] == 'W')
                    map->player.ang = 180 * ANG_PRES;
                else if (layout[index][i] == 'E')
                    map->player.ang = 0 * ANG_PRES;
            }
            i++;
        }
		index++;
        line = get_next_line(fd);
    }
	if (validate_map(layout, index, map) == -1)
		printf("Error\n");
    return (0);
}
*/

int	parse_map(char **map, t_map *map_info)
{
	//char **layout;
    //char *line;
    int index;
    int player_found = 0;

	       // layout = (char **)add_dir(layout, line);
        //index = ft_arraylen(layout) - 1;
        // miramos la posición del jugador
		index = 0;
        while (map[index])
        {
        	int i = 0;
			while (map[index][i])
			{
            if (ft_strchr("NSWE", map[index][i]))
            {
				printf("busca un jugador\n");
                if (player_found) // si ya teniamos un jugador
                {
                    printf("Error\n Multiple player starting positions found.\n");
                    return (-1);
                }
                player_found = 1;
                map_info->player.x = i;
                map_info->player.y = index;
				printf("player x: %f\tplayer y: %f\n", map_info->player.x, map_info->player.y);
                //Si encontramos el jugador, le pegamos la orientación
                if (map[index][i] == 'N')
                    map_info->player.ang = 90 * ANG_PRES;
                else if (map[index][i] == 'S')
                    map_info->player.ang = 270 * ANG_PRES;
                else if (map[index][i] == 'W')
                    map_info->player.ang = 180 * ANG_PRES;
                else if (map[index][i] == 'E')
                    map_info->player.ang = 0 * ANG_PRES;
            }
			i++;
			}
			index++;
        }
        //line = get_next_line(fd);
	if (validate_map(map, index, map_info) == -1)
		printf("Error\n");
    return (0);

}
char	**maping(void)
{
	char	**layout;

	layout = NULL;
	layout = add_dir(layout, ft_strdup("             1111111111 111111"));
	layout = add_dir(layout, ft_strdup("             10000000S11100001"));
	layout = add_dir(layout, ft_strdup("111111111111110000000000000001"));
	layout = add_dir(layout, ft_strdup("100000000000000000000000000001"));
	layout = add_dir(layout, ft_strdup("100000000000000000000000000001"));
	layout = add_dir(layout, ft_strdup("100000000000000000000000000001"));
	layout = add_dir(layout, ft_strdup("100001110000001111111111111111"));
	layout = add_dir(layout, ft_strdup("100001 10000001"));
	layout = add_dir(layout, ft_strdup("111111 11111111"));
	return (layout);
}

int	main()
{
	t_map map;
	parse_map(maping(), &map);
	return (0);	
}
