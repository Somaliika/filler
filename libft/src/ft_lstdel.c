/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:57:53 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:43:59 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst && del)
	{
		if ((*alst)->next == NULL)
			ft_lstdelone(alst, del);
		else
		{
			ft_lstdel(&((*alst)->next), del);
			ft_lstdelone(alst, del);
		}
	}
}
