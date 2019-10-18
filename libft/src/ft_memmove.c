/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:06:39 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:45:59 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int i;

	i = -1;
	if ((unsigned char *)dst <= (unsigned char *)src)
		while (++i < (int)len)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	else
	{
		i = len;
		while (--i >= 0)
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
	}
	return (dst);
}
