/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_topower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:32:50 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 20:32:52 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_topower(int nbr, int power)
{
	long res;
	long tmp;

	if (power == 0)
		return (1);
	tmp = ft_topower(nbr, power - 1);
	res = nbr * tmp;
	if (tmp != 0 && res / tmp != nbr)
		return (0);
	return (res);
}
