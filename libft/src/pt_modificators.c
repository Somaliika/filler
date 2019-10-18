/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modificators.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:44:29 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 16:44:31 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	keep_asterics(t_fsm *fsm)
{
	char	*p;
	char	*a;

	a = ft_strchr(fsm->current->format, '*');
	if (a != NULL)
	{
		p = ft_strrchr(fsm->current->format, '.');
		if (p == NULL)
		{
			fsm->current->width = va_arg(fsm->args, int);
		}
		else if (a > p)
			fsm->current->precision = va_arg(fsm->args, int);
		else
		{
			fsm->current->width = va_arg(fsm->args, int);
			a = ft_strchr(p, '*');
			if (a != NULL)
				fsm->current->precision = va_arg(fsm->args, int);
		}
	}
	fsm->active_state = choose_type;
}

void	choose_type(t_fsm *fsm)
{
	int		type;

	if (ft_strcmp(fsm->current->format, "%") == 0)
	{
		fsm->current->result = ft_strnew(0);
		fsm->current->done = 1;
		return ;
	}
	else if (fsm->current->format[0] != '%')
	{
		fsm->current->result = ft_strdup(fsm->current->format);
		fsm->current->done = 1;
		return ;
	}
	type = (int)get_type(fsm);
	if (fsm->types[type] != NULL)
		fsm->active_state = fsm->types[type];
	else
		fsm->active_state = type_wrong;
}

void	choose_precision(t_fsm *fsm)
{
	char	*p;

	p = ft_strrchr(fsm->current->format, '.');
	if (fsm->current->precision == -1)
	{
		if (!p && get_type(fsm) == 'f')
			fsm->current->precision = 6;
		else if (!p && (fsm->active_state = choose_width))
			return ;
		else if (ft_isdigit(p[1]))
			fsm->current->precision = ABS(ft_atoli(&p[1]));
		else
		{
			fsm->current->precision = 0;
			while (FLAG(p[1]))
				p++;
			if (ft_isdigit(p[1]))
				fsm->current->width = ft_atoli(&p[1]);
		}
	}
	track_error(fsm);
	fsm->active_state = (fsm->precisions[(int)get_type(fsm)] != NULL) ?
		fsm->precisions[(int)get_type(fsm)] : choose_width;
}

void	choose_width(t_fsm *fsm)
{
	char	*w;
	int		i;

	i = 0;
	w = fsm->current->format;
	while (w[i] != '\0')
	{
		while (!ft_isdigit(w[i]) && w[i] != '.' && w[i] != '\0')
			i++;
		if (w[i] == '0')
			i++;
		while (!ft_isdigit(w[i]) && w[i] != '.' && w[i] != '\0')
			i++;
		if (w[i] == '.')
			while (w[i] == '.' || ft_isdigit(w[i]))
				i++;
		if (ft_isdigit(w[i]) && !has_asterics_after_digits(&w[i]))
		{
			fsm->current->width = ft_atoli(&w[i]);
			while (ft_isdigit(w[i]))
				i++;
		}
	}
	track_error(fsm);
	fsm->active_state = flag_octotorp;
}

void	track_error(t_fsm *fsm)
{
	if (fsm->current->precision > MAX_WIDTH &&
		ft_strchr("diouxXfp", get_type(fsm)))
		fsm->error = 1;
	if (fsm->current->width > MAX_WIDTH)
		fsm->error = 1;
}
