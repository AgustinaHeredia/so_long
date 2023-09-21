/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:24:56 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/21 10:55:22 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	perror(str);
	exit (EXIT_FAILURE);
}

static void	inicialice_struct(t_game *game)
{
	game->width = 0;
	game->height = 0;
	game->strbigline = NULL;
	game->map = NULL;
	game->player = 0;
	game->exit = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->apple = 0;
	game->p_move = 0;
	game->count_colec = 0;
	game->mlx = mlx_init();
	if (!game->mlx)
		error_exit("Error. No se ha podido iniciar la libería MLX\n");
	ft_bzero(&(game->img), sizeof(t_xmp));
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		fd;

	if (argc != 2)
		error_exit("Error. El número de argumentos no es válido\n");
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error. No se ha podido iniciar la estructura de game\n");
	inicialice_struct(game);
	fd = arg_check(argc, argv);
	read_map(fd, game);
	check_map(game);
	init_game(game);
	return (0);
}
