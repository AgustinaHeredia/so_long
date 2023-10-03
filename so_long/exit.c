/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:46:29 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/03 14:43:47 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	error_exit(char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

void	error_free_exit(t_game *game, char *str)
{
	free_map(game->map, game->width);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	perror(str);
	exit (EXIT_FAILURE);
}

int	exit_game(t_game *game)
{
	free_map(game->map, game->width);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	ft_printf("Ooohhh... has salido del juego\n");
	exit(0);
}

void	clear_game(t_game *game)
{
	free_map(game->map, game->width);
	mlx_destroy_window(game->mlx, game->win);
	free(game);
	ft_printf("Felicidades!!!!\n");
	ft_printf("Has llegado a casa de la Abuelita <3 <3\n");
	exit(0);
}
