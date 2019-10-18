/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:06 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:13:08 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	result = (char*)s;
	i = ft_strlen(result) + 1;
	while (--i > 0)
	{
		if (result[i] == c)
			return (&result[i]);
	}
	if (result[i] == c)
		return (&result[i]);
	return (NULL);
}
