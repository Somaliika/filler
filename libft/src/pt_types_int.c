/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:36:38 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 17:36:49 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	type_int(t_fsm *fsm)
{
	long long	(*f)(t_fsm*);

	f = fsm->sizes[get_size(fsm)];
	if (f != NULL)
		fsm->current->result = ft_itoa_decimal(f(fsm));
	else
		fsm->current->result = ft_itoa_decimal(va_arg(fsm->args, int));
	fsm->active_state = choose_precision;
}

void	type_int_unsigned(t_fsm *fsm)
{
	unsigned int	arg;
	long long		(*f)(t_fsm*);

	f = fsm->sizes[get_size(fsm)];
	if (f != NULL)
		fsm->current->result = ft_itoa_base_unsigned(f(fsm), 10, 0);
	else
	{
		arg = va_arg(fsm->args, unsigned int);
		fsm->current->result = ft_itoa_base_unsigned(arg, 10, 0);
	}
	fsm->active_state = choose_precision;
}

void	type_hex_int_l(t_fsm *fsm)
{
	unsigned int	arg;
	long long		(*f)(t_fsm*);

	f = fsm->sizes[get_size(fsm)];
	if (f != NULL)
		fsm->current->result = ft_itoa_base_unsigned(f(fsm), 16, UPPER);
	else
	{
		arg = va_arg(fsm->args, unsigned int);
		fsm->current->result = ft_itoa_base_unsigned(arg, 16, UPPER);
	}
	fsm->active_state = choose_precision;
}

void	type_hex_int_s(t_fsm *fsm)
{
	unsigned int	arg;
	long long		(*f)(t_fsm*);

	f = fsm->sizes[get_size(fsm)];
	if (f != NULL)
		fsm->current->result = ft_itoa_base_unsigned(f(fsm), 16, LOWER);
	else
	{
		arg = va_arg(fsm->args, unsigned int);
		fsm->current->result = ft_itoa_base_unsigned(arg, 16, LOWER);
	}
	fsm->active_state = choose_precision;
}

void	type_octal_int(t_fsm *fsm)
{
	unsigned int	arg;
	long long		(*f)(t_fsm*);

	f = fsm->sizes[get_size(fsm)];
	if (f != NULL)
		fsm->current->result = ft_itoa_base_unsigned(f(fsm), 8, 0);
	else
	{
		arg = va_arg(fsm->args, unsigned int);
		fsm->current->result = ft_itoa_base_unsigned(arg, 8, 0);
	}
	fsm->active_state = choose_precision;
}
