/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:49:15 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 14:49:16 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			is_mine(t_game *game, t_point *p)
{
	if (!game || !p)
		return (0);
	if (*(game->player) == '1' &&
		(game->map->field[p->y][p->x] == 'o' ||
		game->map->field[p->y][p->x] == 'O'))
		return (1);
	else if (*(game->player) == '2' &&
		(game->map->field[p->y][p->x] == 'x' ||
		game->map->field[p->y][p->x] == 'X'))
		return (1);
	return (0);
}

int			is_enemy(t_game *game, t_point *p)
{
	if (!game || !p)
		return (0);
	if (*(game->player) == '1' &&
		(game->map->field[p->y][p->x] == 'x' ||
		game->map->field[p->y][p->x] == 'X'))
		return (1);
	else if (*(game->player) == '2' &&
		(game->map->field[p->y][p->x] == 'o' ||
		game->map->field[p->y][p->x] == 'O'))
		return (1);
	return (0);
}

int			is_in_map(t_game *game, t_point *p)
{
	if (p->x < 0 || p->y < 0 ||
		p->x >= game->map->size_x || p->y >= game->map->size_y)
		return (0);
	return (1);
}
