/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/27 20:53:06 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:09:41 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		length;
	char	*dest;

	if (!s1)
		return (NULL);
	length = ft_strlen(s1);
	if (!(dest = (char*)malloc(sizeof(char) * (length + 1))))
		return (NULL);
	ft_strcpy(dest, s1);
	return (dest);
}
