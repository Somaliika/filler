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

int		ft_strrchri(const char *s, int c)
{
	char	*result;
	int		i;

	if (!s)
		return (-1);
	result = (char*)s;
	i = ft_strlen(result) + 1;
	while (--i > 0)
	{
		if (result[i] == c)
			return (i);
	}
	if (result[i] == c)
		return (i);
	return (-1);
}
