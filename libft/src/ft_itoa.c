/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:57:37 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:43:33 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_sign(long *nbr, int *sign)
{
	if (*nbr < 0)
	{
		*sign = 1;
		*nbr *= -1;
	}
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;
	int		length;
	int		sign;
	long	nbr;

	nbr = (long)n;
	sign = 0;
	length = 1;
	i = 0;
	check_sign(&nbr, &sign);
	while (ft_topower(10, length) <= nbr)
		length++;
	if (!(res = ft_strnew(length + sign)))
		return (NULL);
	while (i < length)
	{
		res[i] = nbr % 10 + 48;
		nbr = nbr / 10;
		i++;
	}
	if (sign)
		res[i++] = '-';
	return (ft_strrev(res, i));
}
