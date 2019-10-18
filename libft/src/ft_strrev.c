/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 20:33:33 by ilian             #+#    #+#             */
/*   Updated: 2018/11/04 20:33:35 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str, int length)
{
	int		i;
	int		j;

	j = length - 1;
	i = 0;
	if (!str)
		return (NULL);
	while (i < j)
		ft_chrswap(&str[i++], &str[j--]);
	return (str);
}
