/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:06:09 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:45:37 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *restrict dst, const void *restrict src,
	size_t n)
{
	size_t	i;
	char	*csrc;
	char	*cdst;

	i = -1;
	csrc = (char *)src;
	cdst = (char *)dst;
	while (++i < n)
		cdst[i] = csrc[i];
	return (cdst);
}
