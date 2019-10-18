/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:13:48 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:13:49 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		min;
	int		max;

	min = 0;
	if (!s)
		return (NULL);
	max = ft_strlen(s) - 1;
	while (s[min] != '\0' &&
		(s[min] == ' ' || s[min] == '\n' || s[min] == '\t'))
		min++;
	while (max > min && (s[max] == ' ' || s[max] == '\n' || s[max] == '\t'))
		max--;
	return (ft_strsub(s, min, max - min + 1));
}
