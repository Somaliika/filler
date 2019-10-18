/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:59:00 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:47:53 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *restrict dst, const void *restrict src, int c,
	size_t n)
{
	int				i;
	unsigned char	*udc;
	unsigned char	*usc;
	unsigned char	uc;

	uc = (unsigned char)c;
	udc = (unsigned char *)dst;
	usc = (unsigned char *)src;
	i = -1;
	while (++i < (int)n)
	{
		udc[i] = usc[i];
		if (usc[i] == uc)
			return (&udc[i + 1]);
	}
	return (NULL);
}
