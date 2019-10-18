/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 14:22:35 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 14:22:40 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	flag_octotorp(t_fsm *fsm)
{
	t_regex	*r;
	char	*res;

	r = fsm->current;
	res = r->result;
	if (has_flag(r->format, '#'))
	{
		r->size = rgx_result_size(r);
		if (get_type(fsm) == 'o' && *res != '0')
			r->result = ft_strnjoin("0", r->result, 1, r->size++);
		else if ((get_type(fsm) == 'x' || get_type(fsm) == 'X') &&
			*res != '\0' && !ft_isallequal(res, '0'))
		{
			fsm->active_state = flags_hex_int;
			return ;
		}
		else if (get_type(fsm) == 'f' && ft_strchr(res, '.') == NULL
			&& *res != '\0' && !is_bad_float(res))
			r->result = ft_strnjoin(r->result, ".", r->size++, 1);
		if ((get_type(fsm) == 'o' && *res != '0') ||
		(get_type(fsm) == 'f' && ft_strchr(res, '.') == NULL
			&& *res != '\0' && !is_bad_float(res)))
			FREE(res);
	}
	fsm->active_state = flag_plus;
}

void	flag_plus(t_fsm *fsm)
{
	char	*f;
	t_regex	*r;
	char	*res;

	r = fsm->current;
	f = r->format;
	res = r->result;
	r->size = rgx_result_size(r);
	if (has_flag(f, '+'))
	{
		if (ft_strchr("idf", get_type(fsm)) != NULL &&
			*res != '-' && ft_strstr(res, "nan") == NULL)
		{
			r->result = ft_strnjoin("+", res, 1, r->size++);
			FREE(res);
		}
		fsm->active_state = flag_minus;
	}
	else
		fsm->active_state = flag_space;
}

void	flag_space(t_fsm *fsm)
{
	t_regex	*r;
	char	*res;

	r = fsm->current;
	res = fsm->current->result;
	r->size = rgx_result_size(fsm->current);
	if (has_flag(r->format, ' '))
	{
		if (ft_strchr("idf", get_type(fsm)) != NULL && *res != '-' &&
		*res != '+' && (get_type(fsm) != 'f' || ft_strstr(res, "nan") == NULL))
		{
			r->result = ft_strnjoin(" ", res, 1, r->size++);
			FREE(res);
		}
	}
	fsm->active_state = flag_minus;
}

void	flag_minus(t_fsm *fsm)
{
	t_regex	*r;

	r = fsm->current;
	if (r->width == -1)
		r->done = 1;
	else if (r->width < 0 && (r->width = ABS(r->width)) && r->width > r->size)
		fsm->active_state = expand_right;
	else if (has_flag(r->format, '-') && r->width > r->size)
		fsm->active_state = expand_right;
	else if (r->width > r->size && has_flag(r->format, '0') &&
		(get_type(fsm) != 'f' || !is_bad_float(r->result)))
		fsm->active_state = flag_zero;
	else if (r->width > r->size)
		fsm->active_state = expand_left;
	else
		r->done = 1;
}
