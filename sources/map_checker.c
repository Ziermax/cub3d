int is_valid_char(char c) {
    return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'E' || c == 'W' || c == ' ');
}

int validate_map(char **map, int height)
{
    int i;
    int j;
    int width;
    int row_len;

    i = 0;
    width = 0;
 /*   while (i < height)
    {
        row_len = ft_strlen(map[i]);
        if (row_len > width)
            width = row_len;
        i++;
    }
*/
    i = 0;
    while (i < height)
    {
        j = 0;
        row_len = ft_strlen(map[i]);

        while (j < row_len)
        {
            if (!is_valid_char(map[i][j]))
            {
                fd_printf(2, "Error\n Invalid character in map.\n"); 
                return -1;
            }
            if (i == 0 || i == height - 1) {
                if (map[i][j] != '1' && map[i][j] != ' ')
                {
                    fd_printf(2, "Error\n Map is not closed at the top/bottom edge.\n");
                    return (-1);
                }
            }
            if (j == 0 || j == row_len - 1) {
                if (c != '1' && c != ' ') {
                    fd_printf(2, "Error\n Map is not closed at the left/right edge.\n");
                    return (-1);
                }
            }
            j++;
        }
        i++;
    }
}

int parse_map(int fd, t_map *map) {
    char **layout;
    char *line;
    int index;
    int player_found;
    int line_count;
    int map_ended;

    layout = NULL;
    map_ended = 0;
    player_found = 0;
    index = 0;

    // inicio layout pero aun no sé cuantas líneas de mapa
    layout = (char **)malloc(sizeof(char *));
    if (!layout) {
        fd_printf(2, "Error\n Memory allocation failed\n");
        return (-1);
    }
    //preguntarle a maxi si hay alguna manera de saber cuantas líneas habrá sin leer el fd
    //    line_count = ; para saber las líneas que habrá

    // leer el archivo y almacenar las líneas en layout
    line = get_next_line(fd);
    while (line)
    {
        if (strlen(line) == 0 && map_ended == 0)
        {
            free(line);  // skip empty lines
            line = get_next_line(fd);
            continue;
        }
        if (strlen(line) == 0 && map_ended == 1)
        {
            printf("Error: Map is not closed.\n");
            return -1;
        }
        layout[index] = line;

        // miramos la posisción del jugador
        int i = 0;
        while (layout[index][i])
        {
            if (strchr("NSWE", layout[index][i]))
            {
                if (player_found) // si ya teniamos un jugador
                {
                    fd_printf(2, "Error: Multiple player starting positions found.\n");
                    return (-1);
                }
                player_found = 1;
                map->player.x = i;
                map->player.y = index;
                //Si encontramos el jugador, le pegamos la orientación
                if (layout[index][i] == 'N')
                    map->player.ang = 90 * ANG_PRESS;
                else if (layout[index][i] == 'S')
                    map->player.ang = 270 * ANG_PRESS;
                else if (layout[index][i] == 'W')
                    map->player.ang = 180 * ANG_PRESS;
                else if (layout[index][i] == 'E')
                    map->player.ang = 0 * ANG_PRESS;
            }
            i++;
        }

        index++;
        line = get_next_line(fd);
    }
    layout[index] = NULL;
}
