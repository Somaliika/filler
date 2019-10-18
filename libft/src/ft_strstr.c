/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 18:02:32 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:13:23 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int i;
	int j;

	i = -1;
	if (haystack[0] == '\0' && needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[++i] != '\0')
	{
		j = 0;
		while (needle[j] != '\0' && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char*)(&haystack[i]));
	}
	return (NULL);
}
