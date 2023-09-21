/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:15:31 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/21 11:35:07 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_map_extention(char *argv)
{
	char	*extention;

	extention = ft_strnstr(argv, ".ber", ft_strlen(argv));
	if (!extention)
		return (0);
	return (1);
}

static int	ft_open_ber(char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}

int	arg_check(int argc, char *argv)
{
	int		fd;
	int		flag;

	flag = check_map_extention(argv[1]);
	if (flag == 0)
		error_exit("Error. La extension del archivo no es valida.\n");
	fd = ft_open_ber(argv[1]);
	if (fd == -1)
		error_exit("Error. No se ha podido abrir el archivo.\n");
	return (fd);
}

void	map_obj(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'P' && game->player <= 1)
			{
				game->player_x = row;
				game->player_y = col;
				game->player++;
			}
			if (game->map[row][col] == 'E' && game->exit <= 1)
				game->exit++;
			if (game->map[row][col] == 'C')
				game->apple++;
			col++;
		}
		row++;
	}
}

void	read_map(int fd, t_game *game)
{
	char	*line;

	line = get_next_line(fd);
	game->height = 0;
	game->width = ft_strlen(line) - 1;
	game->strbigline = ft_strdup(line);
	free(line);
	while (line)
	{
		game->height++;
		line = get_next_line(fd);
		if (line)
		{
			game->strbigline = ft_strjoin(game->strbigline, line);
		}
	}
	close(fd);
	game->map = ft_split(game->strbigline, '\n');
	check_map_obj(game);
}
