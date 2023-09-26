/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:15:31 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/26 15:37:30 by agheredi         ###   ########.fr       */
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

int	check_arg_and_fd(int argc, char **argv)
{
	int		fd;
	int		flag;

	if (argc != 2)
	{
		perror("Error. El número de argumentos no es válido\n");
		return (-1);
	}
	flag = check_map_extention(argv[1]);
	if (flag == 0)
	{
		perror("Error. La extension del archivo no es valida.\n");
		return (-1);
	}
	fd = ft_open_ber(argv[1]);
	if (fd == -1)
	{
		perror("Error. No se ha podido abrir el archivo.\n");
		return (-1);
	}
	return (fd);
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
}

void	check_map(t_game *game)
{
	if (all_char_valid(game) != 0)
		error_free_exit(game, "Error. El mapa tiene char no validos\n");
	if (has_exit_player_colect(game) != 0)
		error_free_exit(game, "Error. El mapa tiene char no validos\n");
	if (is_rectangle(game) != 0)
		error_free_exit(game, "Error. El mapa no es un rectángulo\n");
	if (perimeter_check(game) != 0)
		error_free_exit(game, "Error. El perimetro no es correcto\n");
	if (check_map_resolt(game) != 0)
		error_free_exit(game, "Error. El mapa no tiene solución.\n");
	else
		ft_printf("El mapa es correcto, seguimos\n");
}
