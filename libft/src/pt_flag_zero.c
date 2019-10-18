/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag_zero.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/04 19:00:24 by ilian             #+#    #+#             */
/*   Updated: 2019/06/04 19:00:25 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	add_zeros_center(t_regex *r, int w)
{
	char	*t1;
	char	*t2;

	t1 = ft_strfill(w, '0');
	t2 = ft_strnjoin(t1, r->result + 1, w, --r->size);
	FREE(t1);
	t1 = ft_strfill(1, *r->result);
	r->result = ft_strnjoin(t1, t2, 1, w + r->size);
	FREE(t1);
	FREE(t2);
	r->size += w + 1;
}

void	add_zeros_first(t_regex *r, int w)
{
	char	*t1;
	char	*t2;

	t1 = ft_strfill(w, '0');
	t2 = r->result;
	r->result = ft_strnjoin(t1, t2, w, r->size);
	FREE(t1);
	FREE(t2);
	r->size += w;
}

void	flag_zero(t_fsm *fsm)
{
	int		w;
	t_regex	*r;

	r = fsm->current;
	r->size = rgx_result_size(fsm->current);
	w = fsm->current->width - r->size;
	if (ft_strchr("diouxX", get_type(fsm)) != NULL && r->precision > -1)
		fsm->active_state = has_flag(r->format, '-') ?
			expand_right : expand_left;
	else if (r->result[0] == '-' || r->result[0] == '+' ||
			(r->result[0] == ' ' && has_flag(r->format, ' ')))
	{
		add_zeros_center(r, w);
		r->done = 1;
	}
	else
	{
		add_zeros_first(r, w);
		r->done = 1;
	}
}
