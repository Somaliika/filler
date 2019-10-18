/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:58:50 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:45:06 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*temp;
	int		i;

	i = -1;
	if (!(temp = (char*)malloc(size)))
		return (NULL);
	while (++i < (int)size)
		temp[i] = '\0';
	return (temp);
}
