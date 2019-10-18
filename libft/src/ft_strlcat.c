/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:48:42 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:10:44 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *restrict dst, const char *restrict src,
	size_t dstsize)
{
	int				i;
	unsigned int	j;
	size_t			s;

	j = 0;
	i = 0;
	s = ft_strlen(src) + ft_strlen(dst);
	if (ft_strlen(dst) > dstsize)
		return (ft_strlen(src) + dstsize);
	while (dst[j] != '\0')
		j++;
	while (src[i] != '\0' && j < dstsize - 1)
	{
		dst[j] = src[i];
		i++;
		j++;
	}
	while (j < dstsize)
		dst[j++] = '\0';
	return (s);
}
