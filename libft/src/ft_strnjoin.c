/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:10:35 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:10:36 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t l1, size_t l2)
{
	char	*str;
	size_t	i;

	if (!s1 || !s2 || !(str = ft_strnew(l1 + l2 + 1)))
		return (NULL);
	i = 0;
	str = ft_strncpy(str, s1, l1);
	while (i < l2)
	{
		str[l1] = s2[i];
		l1++;
		i++;
	}
	return (str);
}
