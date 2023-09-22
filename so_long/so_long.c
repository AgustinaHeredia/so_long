/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 11:24:56 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/22 15:12:59 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

	fd = check_arg_and_fd(argc, argv);
	if (fd == -1)
		error_exit("Error. Alguno de los argumentos no es valido\n");
	game = malloc(sizeof(t_game));
	if (!game)
		error_exit("Error. No se ha podido iniciar la estructura de game\n");
	inicialice_struct(game);
	read_map(fd, game);
	ft_printf("He llegado hasta aqui0\n");
	check_map(game);
	ft_printf("He llegado hasta aqui6\n");
	//init_game(game);
	return (0);
}
