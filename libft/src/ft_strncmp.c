/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:16:22 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:11:35 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int				i;
	size_t			j;
	unsigned char	*cs1;
	unsigned char	*cs2;

	i = 0;
	j = 0;
	cs1 = (unsigned char*)s1;
	cs2 = (unsigned char*)s2;
	while (cs1[i] != '\0' && cs2[i] != '\0' && j < n)
	{
		if (cs1[i] - cs2[i] != 0)
			return (cs1[i] - cs2[i]);
		i++;
		j++;
	}
	if ((cs1[i] == '\0' && cs2[i] == '\0') || j == n)
		return (0);
	else if (cs1[i] == '\0')
		return (-cs2[i]);
	else
		return (cs1[i]);
}
