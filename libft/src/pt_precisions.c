/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precisions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:33:26 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 17:33:28 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	precision_int(t_fsm *fsm)
{
	int		p;
	int		size;
	char	*res;

	p = fsm->current->precision;
	res = fsm->current->result;
	size = rgx_result_size(fsm->current);
	if (p == 0 && size == 1 && res[0])
		ft_strclr(fsm->current->result);
	else if (p > 0 && (res[0] == '+' || res[0] == '-') && p > size - 1)
	{
		fsm->current->result = ft_strjoinndel(ft_strfill(1, res[0]),
			ft_strjoinndel(ft_strfill(p - size + 1, '0'), res + 1, Y, N), Y, Y);
		FREE(res);
	}
	else if (p > 0 && p > size)
		fsm->current->result =
			ft_strjoinndel(ft_strfill(p - size, '0'), res, Y, Y);
	fsm->active_state = choose_width;
}

void	precision_float(t_fsm *fsm)
{
	int		p;
	char	*res;

	p = fsm->current->precision;
	res = ft_strchr(fsm->current->result, '.');
	if (res++ != NULL)
	{
		if (p > 0 && p > (int)ft_strlen(res))
			fsm->current->result = ft_strjoinndel(fsm->current->result,
				ft_strfill(p - ft_strlen(res), '0'), Y, Y);
		else if (p == 0)
			ft_strclr(res - 1);
		else if (p > 0 && p < (int)ft_strlen(res))
		{
			if (res[p] > '4')
				res[p - 1]++;
			ft_strclr(res + p);
		}
	}
	fsm->active_state = choose_width;
}

void	precision_string(t_fsm *fsm)
{
	int		p;
	int		size;
	char	*temp;

	p = fsm->current->precision;
	size = rgx_result_size(fsm->current);
	if (p > 0 && p < size)
	{
		temp = ft_strsub(fsm->current->result, 0, p);
		FREE(fsm->current->result);
		fsm->current->result = temp;
		fsm->current->size = p;
	}
	else if (p == 0 && size > 0)
	{
		fsm->current->result = ft_strnew(0);
		fsm->current->size = p;
	}
	fsm->active_state = choose_width;
}

void	precision_pointer(t_fsm *fsm)
{
	int		p;
	int		size;
	t_regex	*r;
	char	*temp;

	r = fsm->current;
	p = r->precision;
	size = rgx_result_size(r);
	if (p > size - 2 && r->result[0] == '0' && r->result[1] == 'x')
	{
		temp = ft_strjoinndel(ft_strfill(p - size + 2, '0'),
			r->result + 2, Y, N);
		FREE(r->result);
		r->result = ft_strjoinndel("0x", temp, N, Y);
		r->size = p;
	}
	fsm->active_state = choose_width;
}
