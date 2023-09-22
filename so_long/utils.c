/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agheredi <agheredi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:10:19 by agheredi          #+#    #+#             */
/*   Updated: 2023/09/22 11:16:59 by agheredi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_game *game, char **tab, int x, int y)
{
	if (x < 0 || x >= game->height || y < 0 || y >= game->width
		|| game->map[x][y] == '1' || game->map[x][y] == 'F')
		return ;
	tab[x][y] = 'F';
	flood_fill(game, tab, x - 1, y);
	flood_fill(game, tab, x + 1, y);
	flood_fill(game, tab, x, y - 1);
	flood_fill(game, tab, x, y +1);
}

char	**create_copy_map(char **map, int height, int width)
{
	char	**temp;
	int		i;
	int		j;

	temp = (char **)malloc(height * sizeof(char *));
	if (!temp)
		error_exit("Error. No se ha podido asignar memoria al map Temp\n");
	i = 0;
	while (i <= height)
	{
		temp[i] = ft_substr(map[i], 0, width);
		if (!temp[i])
		{
			j = 0;
			while (j < i)
			{
				free(temp[j]);
				j++;
			}
			free(temp);
			error_exit("Error. No se ha podido asignar memoria en mapTemp\n");
		}
		i++;
	}
	return (temp);
}

void	free_map(char **tab, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
