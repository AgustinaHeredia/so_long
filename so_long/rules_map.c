/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 15:29:05 by agheredi          #+#    #+#             */
/*   Updated: 2023/10/03 13:50:16 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	all_char_valid(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] != 'P' && game->map[row][col] != 'E'
				&& game->map[row][col] != '0' && game->map[row][col] != '1'
				&& game->map[row][col] != 'C')
				return (-1);
			if (game->map[row][col] == 'P')
			{
				game->player_x = row;
				game->player_y = col;
			}
			col++;
		}
		row++;
	}
	return (0);
}

int	has_exit_player_colect(t_game *game)
{
	int	row;
	int	col;

	row = 0;
	while (game->map[row])
	{
		col = 0;
		while (game->map[row][col])
		{
			if (game->map[row][col] == 'E')
				position_exit(game, row, col);
			if (game->map[row][col] == 'P')
				game->player++;
			if (game->map[row][col] == 'C')
				game->apple++;
			col++;
		}
		row++;
	}
	if (game->exit != 1 || game->apple <= 0 || game->player != 1)
		return (-1);
	return (0);
}

int	is_rectangle(t_game *game)
{
	int	x;
	int	y;
	int	size;

	size = ft_strlen(game->map[0]);
	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = ft_strlen(game->map[y]);
		if (x != size)
			return (-1);
		y++;
	}
	return (0);
}

int	perimeter_check(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[0][j] != '1' || game->map[game->height - 1][j] != '1')
				return (-1);
			if (game->map[i][0] != '1' || game->map[i][game->width - 1] != '1')
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map_resolt(t_game *game)
{
	char	**temp;
	int		i;
	int		j;

	temp = create_copy_map(game->map, game->height);
	flood_fill(game, temp, game->player_x, game->player_y);
	i = 0;
	while (temp[i])
	{
		j = 0;
		while (temp[i][j])
		{
			if (temp[i][j] == 'E' || temp[i][j] == 'P' || temp[i][j] == 'C')
			{
				free_map(temp, game->height);
				return (-1);
			}
			j++;
		}
		i++;
	}
	free_map(temp, game->height);
	return (0);
}
