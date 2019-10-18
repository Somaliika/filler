/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 18:12:27 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 18:12:40 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*temp;
	int		i;

	i = -1;
	temp = (char*)malloc(size + 1);
	if (temp == NULL)
		return (NULL);
	while (++i <= (int)size)
		temp[i] = '\0';
	return (temp);
}
