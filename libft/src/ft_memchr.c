/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:05:46 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:45:29 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*result;
	size_t			i;
	unsigned char	c1;

	result = (unsigned char*)s;
	c1 = (unsigned char)c;
	i = -1;
	while (++i < n)
	{
		if (result[i] == c1)
			return (&(result[i]));
	}
	return (NULL);
}
