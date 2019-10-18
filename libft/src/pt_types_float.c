/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types_float.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 20:31:21 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 20:31:24 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void		type_float(t_fsm *fsm)
{
	long double		num;
	int				size;
	unsigned int	negative;

	size = get_size(fsm);
	if (size == 'l')
		num = va_arg(fsm->args, double);
	else if (size == 'L')
		num = va_arg(fsm->args, long double);
	else
		num = va_arg(fsm->args, double);
	negative = (*((__uint128_t*)&num) << (127 - 79)) >> 127;
	if (ISINF(num))
		fsm->current->result = ft_strdup("inf");
	else if (ISNAN(num))
		fsm->current->result = ft_strdup("nan");
	else
		fsm->current->result = float_to_string(num, fsm->current->precision);
	if (negative && *(fsm->current->result) != '-' && !ISNAN(num))
		fsm->current->result = ft_strjoinndel("-", fsm->current->result, N, Y);
	fsm->active_state = precision_float;
}

char		*make_string_from_nums(long double integer,
	long double fraction, int precision)
{
	char	*buf;
	int		dif_len;

	dif_len = precision - digit_count(fraction, 10);
	buf = ft_itoa_base_double(integer);
	if (fraction != 0 || dif_len > 0)
	{
		buf = ft_strjoinndel(buf, ".", Y, N);
		if (dif_len > 0)
			buf = ft_strjoinndel(buf, ft_strfill(dif_len, '0'), Y, Y);
		buf = ft_strjoinndel(buf, ft_itoa_base_double(fraction), Y, Y);
	}
	return (buf);
}

char		*float_to_string(long double num, long long prec)
{
	long double	integ;
	long double	part;
	char		*buf;
	long double	eps;

	prec = MIN(prec, MAX_PREC);
	integ = ABS(num);
	part = epsilon(integ) * to_power_double(10, prec);
	eps = epsilon(part);
	if (eps == 0.5 && prec > 0)
		part = ROUND_TO_EVEN(part);
	else if (eps == 0.5)
		integ = ROUND_TO_EVEN(integ);
	else if (eps > 0.5 && prec > 0)
		part++;
	else if (eps > 0.5)
		integ++;
	if (digit_count(part, 10) > prec)
	{
		integ++;
		part = part - to_power_double(10, digit_count(part, 10));
	}
	buf = make_string_from_nums(integ, part, prec);
	return (buf);
}

long double	epsilon(long double num)
{
	long double	digits;

	digits = to_power_double(10, digit_count(num, 10));
	while (digits > 1)
	{
		digits = digits / 10;
		num -= ((int)(num / digits)) * digits;
	}
	return (num);
}

int			is_bad_float(char *result)
{
	return (!(ft_strstr(result, "nan") == NULL &&
		ft_strstr(result, "inf") == NULL));
}
