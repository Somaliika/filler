/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sizes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:34:12 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 17:34:13 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long long	size_signed_char(t_fsm *fsm)
{
	if (ft_strchr("di", get_type(fsm)) != NULL)
		return ((char)va_arg(fsm->args, int));
	else
		return ((unsigned char)va_arg(fsm->args, unsigned int));
}

long long	size_short_int(t_fsm *fsm)
{
	if (ft_strchr("di", get_type(fsm)) != NULL)
		return ((short int)va_arg(fsm->args, int));
	else
		return ((unsigned short int)va_arg(fsm->args, unsigned int));
}

long long	size_long_int(t_fsm *fsm)
{
	if (get_type(fsm) == 'f')
		return (va_arg(fsm->args, long double));
	else
		return (va_arg(fsm->args, unsigned long));
}

long long	size_long_long(t_fsm *fsm)
{
	return (va_arg(fsm->args, unsigned long long));
}
