/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:43:21 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 16:43:23 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		map_types(t_fsm *fsm)
{
	fsm->types['d'] = type_int;
	fsm->types['i'] = type_int;
	fsm->types['u'] = type_int_unsigned;
	fsm->types['o'] = type_octal_int;
	fsm->types['X'] = type_hex_int_l;
	fsm->types['x'] = type_hex_int_s;
	fsm->types['f'] = choose_precision;
	fsm->types['c'] = type_char;
	fsm->types['s'] = type_string;
	fsm->types['p'] = type_pointer;
	fsm->types['%'] = type_percent;
}

void		map_sizes(t_fsm *fsm)
{
	fsm->sizes['L'] = size_long_int;
	fsm->sizes['l'] = size_long_int;
	fsm->sizes['l' + 'l'] = size_long_long;
	fsm->sizes['h'] = size_short_int;
	fsm->sizes['h' + 'h'] = size_signed_char;
}

void		map_precisions(t_fsm *fsm)
{
	fsm->precisions['i'] = precision_int;
	fsm->precisions['d'] = precision_int;
	fsm->precisions['o'] = precision_int;
	fsm->precisions['u'] = precision_int;
	fsm->precisions['x'] = precision_int;
	fsm->precisions['X'] = precision_int;
	fsm->precisions['f'] = type_float;
	fsm->precisions['s'] = precision_string;
	fsm->precisions['p'] = precision_pointer;
}

void		push_map_item(t_key_func *map, char *key, void (*func)())
{
	t_key_func *item;

	if (map)
	{
		while (map->next)
			map = map->next;
		item = (t_key_func *)malloc(sizeof(t_key_func));
		(*item) = (t_key_func){key, func, NULL};
		map->next = item;
	}
}

t_key_func	*create_map(char *key, void (*func)())
{
	t_key_func *item;

	item = (t_key_func *)malloc(sizeof(t_key_func));
	(*item) = (t_key_func){key, func, NULL};
	return (item);
}
