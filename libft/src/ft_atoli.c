/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/16 15:47:17 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:42:17 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int		ft_atoli(const char *str)
{
	int					i;
	unsigned long int	res;
	int					sign;

	i = 0;
	res = 0;
	sign = 0;
	while (str[i] != '\0' && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
		i++;
	if (str[i] == '-')
		sign = 1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res > 9223372036854775807)
			return (sign ? 0 : -1);
		i++;
	}
	if (sign)
		return (res * -1);
	return (res);
}
