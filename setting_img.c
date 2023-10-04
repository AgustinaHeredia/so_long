/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 09:41:34 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/03 15:25:23 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setting_map_b(t_game *game)
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
					game->img_player_b, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}

void	setting_map_f(t_game *game)
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
					game->img_player_f, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}

void	setting_map_r(t_game *game)
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
					game->img_player_r, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}

void	setting_map_l(t_game *game)
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
					game->img_player_l, col * IMG_PX, row * IMG_PX);
			else if (game->map[row][col] == 'E')
				mlx_put_image_to_window(game->mlx, game->win,
					game->img_exit, col * IMG_PX, row * IMG_PX);
			col++;
		}
		row++;
	}
}
