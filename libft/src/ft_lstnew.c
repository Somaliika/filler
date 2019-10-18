/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:58:41 by ilian             #+#    #+#             */
/*   Updated: 2018/11/10 20:44:38 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*link;
	void	*copied;

	if (!(link = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	copied = NULL;
	if (content_size)
		if (!(copied = ft_memalloc(content_size)))
			return (NULL);
	link->content = (content == NULL) ? NULL : ft_memcpy(copied,
		content, content_size);
	link->content_size = (content == NULL) ? 0 : content_size;
	link->next = NULL;
	return (link);
}
