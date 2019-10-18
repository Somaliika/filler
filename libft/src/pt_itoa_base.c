/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:32:56 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 18:32:58 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double			to_power_double(long double nbr, int power)
{
	if (power == 0)
		return (1);
	return (nbr * to_power_double(nbr, power - 1));
}

char				*make_hex(char *str, unsigned long long n,
	unsigned long long base, int type)
{
	if (n >= base)
		str = make_hex(++str, n / base, base, type);
	if (n % base < 10)
		*str = (n % base) + '0';
	else
		*str = (n % base) - 10 + type;
	return (str);
}

char				*ft_itoa_base_unsigned(unsigned long long nbr,
	int base, int type)
{
	char				*res;
	int					length;
	unsigned long long	temp;
	unsigned long long	old_temp;

	length = 1;
	old_temp = 0;
	while ((temp = POWER_UNSIGN(base, length))
		&& temp <= nbr && temp != 0 && old_temp < temp)
	{
		length++;
		old_temp = temp;
	}
	res = (char*)malloc(sizeof(char) * (length + 1));
	res[length--] = '\0';
	if (nbr == 0)
		res[length] = '0';
	while (nbr > 0)
	{
		res[length] = *(make_hex(&(res[length]), nbr % base, base, type));
		nbr = nbr / base;
		length--;
	}
	return (res);
}

char				*ft_itoa_decimal(long long nbr)
{
	if (nbr < 0)
		return (ft_strjoinndel("-", ft_itoa_base_unsigned(-nbr, 10, 0), N, Y));
	else
		return (ft_itoa_base_unsigned(nbr, 10, 0));
}

char				*ft_itoa_base_double(long double nbr)
{
	char		*res;
	int			length;
	int			i;
	long double	d;

	if (nbr < 1)
		return (ft_strdup("0"));
	i = 0;
	length = digit_count(nbr, 10);
	res = ft_strnew(length);
	if (nbr == 0)
		res[length] = '0';
	d = to_power_double(10, length);
	while (d > 1 && i < length)
	{
		d /= 10;
		res[i] = 48 + (int)(nbr / d);
		nbr -= (res[i++] - 48) * d;
	}
	return (res);
}
