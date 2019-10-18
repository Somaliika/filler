/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:17:29 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 18:17:30 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_regex		*buffercat(t_regex *buffer, t_regex *rgx)
{
	int i;

	i = 0;
	if (rgx->result == NULL)
		rgx->result = ft_strdup("(null)");
	rgx->size = rgx_result_size(rgx);
	if (!is_overflow(buffer, rgx))
	{
		while (i < rgx->size && buffer->size < BUFSIZE)
		{
			buffer->result[buffer->size] = rgx->result[i];
			i++;
			buffer->size++;
			buffer->width++;
		}
		buffer->result[buffer->size] = '\0';
	}
	return (buffer);
}

int			is_overflow(t_regex *buffer, t_regex *rgx)
{
	if (buffer->size + rgx->size >= BUFSIZE)
	{
		ft_putnstr(buffer->result, buffer->size);
		ft_memset(buffer->result, 0, BUFSIZE);
		buffer->size = 0;
	}
	if (rgx->size >= BUFSIZE)
	{
		ft_putnstr(rgx->result, rgx->size);
		buffer->width += rgx->size;
		return (1);
	}
	return (0);
}

t_regex		*create_buffer(void)
{
	t_regex *buffer;

	buffer = create_rgx(NULL, 0, N);
	buffer->width = 0;
	buffer->result = ft_memalloc(BUFSIZE);
	return (buffer);
}

void		clear_list(t_regex *r)
{
	if (!r)
		return ;
	clear_list(r->next);
	if (r->result)
		FREE(r->result);
	if (r->format)
		FREE(r->format);
	FREE(r);
}
