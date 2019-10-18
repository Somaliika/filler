/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:05:56 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:45:46 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int				i;
	size_t			j;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	j = 0;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (j < n)
	{
		if ((cs1)[i] - (cs2)[i] != 0)
			return (cs1[i] - cs2[i]);
		i++;
		j++;
	}
	return (0);
}
