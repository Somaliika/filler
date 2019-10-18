/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 17:48:27 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 17:48:29 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strfill(size_t size, char c)
{
	char	*temp;
	int		i;

	i = -1;
	temp = (char*)malloc(size + 1);
	if (temp == NULL)
		return (NULL);
	while (++i <= (int)size)
		temp[i] = c;
	temp[size] = '\0';
	return (temp);
}
