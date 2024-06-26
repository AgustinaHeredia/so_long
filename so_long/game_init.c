/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:42:07 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/03 12:02:51 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	upload_img(t_game *game)
{
	int	img_width;
	int	img_height;

	game->img_floor = mlx_xpm_file_to_image(game->mlx,
			"./textures/pasto.xpm", &img_width, &img_height);
	game->img_wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/arbol1.xpm", &img_width, &img_height);
	game->img_player_b = mlx_xpm_file_to_image(game->mlx,
			"./textures/caperucitaespalda.xpm", &img_width, &img_height);
	game->img_player_f = mlx_xpm_file_to_image(game->mlx,
			"./textures/capericitafrente.xpm", &img_width, &img_height);
	game->img_player_r = mlx_xpm_file_to_image(game->mlx,
			"./textures/caperucitadere.xpm", &img_width, &img_height);
	game->img_player_l = mlx_xpm_file_to_image(game->mlx,
			"./textures/caperucitaizq.xpm", &img_width, &img_height);
	game->img_collectable = mlx_xpm_file_to_image(game->mlx,
			"./textures/apple1.xpm", &img_width, &img_height);
	game->img_exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/house1.xpm", &img_width, &img_height);
}

void	paint_backgroud(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			mlx_put_image_to_window(game->mlx, game->win, game->img_floor,
				col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}

void	init_game(t_game *game)
{
	game->win = mlx_new_window(game->mlx, game->width * IMG_PX,
			game->height * IMG_PX, "So long");
	upload_img(game);
	paint_backgroud(game);
	setting_map_f(game);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &press_key, game);
	mlx_hook(game->win, X_EVENT_KEY_EXIT, 0, &exit_game, game);
	mlx_loop(game->mlx);
}
