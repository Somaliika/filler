/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 22:34:13 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:09:17 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcpy(char *dst, const char *src)
{
	int in;

	in = 0;
	if (!dst)
		return (NULL);
	while (src && src[in] != '\0')
	{
		dst[in] = src[in];
		in++;
	}
	dst[in] = '\0';
	return (dst);
}
