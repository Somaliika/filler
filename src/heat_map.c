/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:20:03 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 14:20:05 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		*g_i;
t_point		*g_j;

/*
**  For each cell function loops through all neighbors
**  to set the value at one pount bigger than the cell itself
*/

int		fill_neighbors(t_game *game, t_point *p, int value)
{
	int	i;
	int	changes;

	i = 0;
	changes = 0;
	if ((is_enemy(game, p) && value == 0) ||
		(value && game->map->heat_map[p->y][p->x] == value))
		value++;
	else
		return (0);
	while (i < 8)
	{
		set_coordinates(g_j, p->x + game->offsets[i][0],
			p->y + game->offsets[i][1]);
		if (is_in_map(game, g_j) && !is_enemy(game, g_j) &&
			game->map->heat_map[g_j->y][g_j->x] == 0 && ++changes)
			game->map->heat_map[g_j->y][g_j->x] = value;
		i++;
	}
	return (changes);
}

/*
**  Heat map is the score for each map cell that shows
**  how close this cell is to enemy
*/

void	fill_heat_map(t_game *game)
{
	int			empty;
	int			value;
	int			changes;

	set_coordinates(g_i, 0, 0);
	empty = game->map->size_y * game->map->size_x;
	value = 0;
	changes = 1;
	while (changes)
	{
		changes = 0;
		g_i->y = 0;
		while (g_i->y < game->map->size_y)
		{
			g_i->x = 0;
			while (g_i->x < game->map->size_x)
			{
				if (fill_neighbors(game, g_i, value) != 0)
					changes++;
				g_i->x++;
			}
			g_i->y++;
		}
		value++;
	}
}
