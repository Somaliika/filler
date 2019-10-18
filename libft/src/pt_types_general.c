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

void	type_char(t_fsm *fsm)
{
	fsm->current->result = ft_strnew(1);
	fsm->current->result[0] = va_arg(fsm->args, int);
	if (fsm->current->result[0] == 0)
		fsm->current->size = 1;
	fsm->active_state = choose_precision;
}

void	type_string(t_fsm *fsm)
{
	char *res;

	res = va_arg(fsm->args, char*);
	if (res == NULL)
		fsm->current->result = ft_strdup("(null)");
	else
		fsm->current->result = ft_strdup(res);
	fsm->active_state = choose_precision;
}

void	type_pointer(t_fsm *fsm)
{
	unsigned long nbr;

	nbr = (unsigned long)((uintptr_t)va_arg(fsm->args, void*));
	fsm->current->result = ft_strjoinndel("0x",
		ft_itoa_base_unsigned(nbr, 16, LOWER), N, Y);
	fsm->active_state = choose_precision;
}

void	type_percent(t_fsm *fsm)
{
	fsm->current->result = ft_strnew(1);
	fsm->current->result[0] = '%';
	fsm->active_state = choose_precision;
}

void	type_wrong(t_fsm *fsm)
{
	fsm->current->result = ft_strfill(1, get_type(fsm));
	fsm->active_state = choose_precision;
}
