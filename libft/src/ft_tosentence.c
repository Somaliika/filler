/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tosentence.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:33:58 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 20:34:00 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_tosentence(char *s)
{
	char	*sent;
	int		i;
	int		up;

	i = -1;
	up = 1;
	if (!s || !(sent = ft_strdup(s)))
		return (NULL);
	while (sent[++i] != '\0')
	{
		if (up)
		{
			sent[i] = ft_toupper(sent[i]);
			up = 0;
		}
		if (sent[i] == 10 || sent[i] == 33 ||
			sent[i] == 46 || sent[i] == 63)
			up = 1;
	}
	return (sent);
}
