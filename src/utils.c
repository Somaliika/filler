/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:52:48 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 14:52:50 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		copy_point(t_point *from, t_point **to)
{
	if (!from)
		return ;
	if (!*to)
	{
		*to = create_point(from->x, from->y);
		return ;
	}
	(*to)->x = from->x;
	(*to)->y = from->y;
}

void		set_coordinates(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
}

t_point		*create_point(int x, int y)
{
	t_point	*p;

	p = (t_point *)malloc(sizeof(t_point));
	p->x = x;
	p->y = y;
	return (p);
}

void		create_heat_map(t_field *map)
{
	int	i;

	i = -1;
	map->heat_map = (int**)ft_memalloc(map->size_y * sizeof(int*));
	while (++i < map->size_y)
		map->heat_map[i] = (int*)ft_memalloc(map->size_x * sizeof(int));
}
