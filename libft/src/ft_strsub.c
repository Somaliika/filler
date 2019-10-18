/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:34 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:13:36 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	int		j;
	char	*str;

	i = (int)start - 1;
	j = 0;
	if (!s || start > ft_strlen(s))
		return (NULL);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[++i] != '\0' && i < (int)start + (int)len)
		str[j++] = s[i];
	str[j++] = '\0';
	while (++i < (int)start + (int)len)
		str[j++] = '\0';
	return (str);
}
