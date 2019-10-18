/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:57:47 by ilian             #+#    #+#             */
/*   Updated: 2019/06/28 18:57:48 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	clear_heat_map(t_field *map)
{
	int	i;

	if (!map->heat_map)
		return ;
	i = 0;
	while (i < map->size_y)
	{
		ft_bzero(map->heat_map[i], map->size_x * sizeof(int));
		i++;
	}
}

void	clear_field(t_field *map, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_strclr(map->field[i]);
		i++;
	}
	clear_heat_map(map);
}
