/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:16 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:13:18 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_length(const char *str, char c)
{
	int i;
	int size;

	size = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c)
		{
			size++;
			while (str[i] != '\0' && str[i] != c)
				i++;
		}
		else
			i++;
	}
	return (size);
}

char		**ft_strsplit(char const *s, char c)
{
	int		size;
	int		i;
	char	**array;
	int		j;

	i = -1;
	j = 0;
	size = 0;
	if (s == NULL || c == 0 ||
		!(array = (char**)malloc(sizeof(char*) * (ft_length(s, c) + 1))))
		return (NULL);
	while (s[++i] != '\0')
	{
		if (size != 0 && s[i] == c)
		{
			array[j++] = ft_strsub(s, i - size, size);
			size = 0;
		}
		else if (s[i] != c)
			size++;
	}
	if (size != 0)
		array[j++] = ft_strsub(s, i - size, size);
	array[j++] = NULL;
	return (array);
}
