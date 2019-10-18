/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:28:39 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 14:28:41 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		*g_i;
t_point		*g_j;

/*
**  Counting the sum of heat scores for placing piece
**  The smaller it is, the better it will be to place it there
*/

int			count_heat(t_game *game, t_point *p, int res, int mine)
{
	set_coordinates(g_i, 0, 0);
	set_coordinates(g_j, p->x, p->y);
	while (g_i->y < game->piece->size_y)
	{
		while (g_i->x < game->piece->size_x)
		{
			if (game->piece->field[g_i->y][g_i->x] == '*')
			{
				if (!is_in_map(game, g_j) || (is_in_map(game, g_j) &&
					is_enemy(game, g_j)))
					return (-1);
				if (is_mine(game, g_j))
					mine++;
				res += game->map->heat_map[g_j->y][g_j->x];
			}
			g_i->x++;
			g_j->x++;
		}
		set_coordinates(g_i, 0, g_i->y + 1);
		set_coordinates(g_j, p->x, g_j->y + 1);
	}
	return ((mine == 1) ? res : -1);
}

/*
**  Search for first mention of last enemy location
*/

t_point		*get_new_enemy(t_game *game)
{
	set_coordinates(g_i, 0, 0);
	while (g_i->y < game->map->size_y)
	{
		while (g_i->x < game->map->size_x)
		{
			if ((*(game->player) == '1' &&
				game->map->field[g_i->y][g_i->x] == 'x') ||
				(*(game->player) == '2' &&
				game->map->field[g_i->y][g_i->x] == 'o'))
				return (g_i);
			g_i->x++;
		}
		g_i->x = 0;
		g_i->y++;
	}
	return (NULL);
}

/*
**  Function decides which point is closer to last enemy location
**  between two points with similar scores
*/

int			is_better(t_game *game, t_point *new, t_point *old)
{
	t_point	*enemy;
	int		new_score;
	int		old_score;

	enemy = get_new_enemy(game);
	if (!enemy)
		return (0);
	new_score = ABS(new->x - enemy->x) + ABS(new->y - enemy->y);
	old_score = ABS(old->x - enemy->x) + ABS(old->y - enemy->y);
	return (new_score < old_score);
}

/*
**  Looping through all possible locations to place a piece
**  The best one is chosen after its heat score
**  Gap showes the level of similarity of score to take advantage
**  with closeness to enemy
*/

t_point		*place(t_game *game)
{
	t_point	*bestp;
	int		res;
	int		bestres;
	t_point	*p;

	bestres = -1;
	bestp = NULL;
	p = create_point(-game->piece->size_x, -game->piece->size_y);
	while (p->y < game->map->size_y)
	{
		while (p->x < game->map->size_x)
		{
			res = count_heat(game, p, 0, 0);
			if (res > 0 && (bestres == -1 || res < bestres - GAP ||
				(is_better(game, p, bestp) && res <= bestres)))
			{
				bestres = res;
				copy_point(p, &bestp);
			}
			p->x++;
		}
		set_coordinates(p, -game->piece->size_x, p->y + 1);
	}
	FREE(p);
	return (bestp);
}
