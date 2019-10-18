/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:08:54 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:49:53 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	char	*result;
	int		i;

	if (!s)
		return (NULL);
	result = (char*)&(s[0]);
	i = -1;
	while (result[++i] != '\0')
	{
		if (result[i] == c)
			return (&result[i]);
	}
	if (result[i] == c)
		return (&result[i]);
	return (NULL);
}
