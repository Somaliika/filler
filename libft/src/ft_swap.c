/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/13 08:40:50 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 20:32:40 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_swap(void *a, void *b, size_t size)
{
	void *temp;

	if (a != NULL && b != NULL)
	{
		temp = malloc(size);
		ft_memcpy(temp, a, size);
		ft_memcpy(a, b, size);
		ft_memcpy(b, temp, size);
		free(temp);
	}
}
