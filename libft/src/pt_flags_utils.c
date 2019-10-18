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

void	flags_hex_int(t_fsm *fsm)
{
	t_regex	*r;
	char	*temp;
	int		w;
	int		s;

	r = fsm->current;
	s = rgx_result_size(r);
	w = r->width - s;
	if (has_flag(r->format, '0') && !has_flag(r->format, '-')
		&& r->precision == -1 && w > 0)
	{
		temp = ft_strjoinndel(ft_strfill(w - 2, '0'), r->result, Y, Y);
		r->result = ft_strjoinndel((get_type(fsm) == 'x') ?
			"0x" : "0X", temp, N, Y);
		r->size = r->width;
	}
	else
	{
		r->result = ft_strjoinndel((get_type(fsm) == 'x') ?
			"0x" : "0X", r->result, N, Y);
		r->size += 2;
	}
	fsm->active_state = flag_plus;
}

void	expand_right(t_fsm *fsm)
{
	char	*res;
	char	*spaces;
	int		w;
	int		size;

	res = fsm->current->result;
	size = rgx_result_size(fsm->current);
	w = fsm->current->width - size;
	spaces = ft_strfill(w, ' ');
	fsm->current->result = ft_strnjoin(res, spaces, size, w);
	fsm->current->size = w + size;
	fsm->current->done = 1;
	FREE(res);
	FREE(spaces);
}

void	expand_left(t_fsm *fsm)
{
	char	*res;
	char	*spaces;
	int		w;
	int		size;

	res = fsm->current->result;
	size = rgx_result_size(fsm->current);
	w = fsm->current->width - size;
	spaces = ft_strfill(w, ' ');
	fsm->current->result = ft_strnjoin(spaces, res, w, size);
	fsm->current->size = fsm->current->width;
	fsm->current->done = 1;
	FREE(res);
	FREE(spaces);
}

int		has_flag(char *format, char c)
{
	int	i;

	i = 0;
	if (c == '0')
	{
		while (format[i] != '\0')
		{
			if (i != 0 && format[i] == c && format[i - 1] != c &&
				(format[i - 1] == '%' || FLAG(format[i - 1])))
				return (1);
			i++;
		}
		return (0);
	}
	return (ft_strchr(format, c) != NULL ? 1 : 0);
}

int		digit_count(long double n, int base)
{
	int l;

	l = 0;
	while (n >= 1)
	{
		n /= base;
		l++;
	}
	return (l);
}
