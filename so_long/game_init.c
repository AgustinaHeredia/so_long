/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/26 15:42:07 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/28 15:26:14 by agheredi         ###   ########.fr       */
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
	game->img_player = mlx_xpm_file_to_image(game->mlx,
			"./textures/capericitafrente.xpm", &img_width, &img_height);
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

void	seting_map(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (row < game->height)
	{
		col = 0;
		while (col < game->width)
		{
			if (game->map[row][col] == '1')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_wall, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'C')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_collectable, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_player, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, col * IMG_PX, row * IMG_PX);
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
	seting_map(game);
	ft_printf("La posicion inicial del player es x: %d, y: %d\n",
		game->player_x, game->player_y);
	mlx_hook(game->win, X_EVENT_KEY_RELEASE, 0, &key_press, game);
	mlx_loop(game->mlx);
}
