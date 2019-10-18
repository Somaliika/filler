/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strarcat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:33:47 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:49:44 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr_count(char const **arr)
{
	int	i;
	int j;
	int chrs;

	i = -1;
	chrs = 0;
	while (arr[++i] != NULL)
	{
		if (i > 0)
			chrs++;
		j = -1;
		while (arr[i][++j] != '\0')
			chrs++;
	}
	return ((chrs) ? chrs : 1);
}

char		*ft_strarcat(char const **arr, char del)
{
	char	*str;
	int		i;

	i = 0;
	if (!arr || !(str = ft_strnew(chr_count(arr))))
		return (NULL);
	while (arr[i] != NULL)
	{
		if (i > 0)
			str = ft_strncat(str, &del, 1);
		str = ft_strcat(str, arr[i++]);
	}
	return (str);
}
