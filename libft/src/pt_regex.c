/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   regex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:01:38 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 18:01:39 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_regex		*create_rgx(char *format, int i, int save_format)
{
	t_regex *rgx;

	rgx = (t_regex*)malloc(sizeof(t_regex));
	if (format && save_format)
		rgx->format = format;
	else if (format)
		rgx->format = ft_strdup(format);
	else
		rgx->format = NULL;
	rgx->next = NULL;
	rgx->i = i;
	rgx->width = -1;
	rgx->precision = -1;
	rgx->done = 0;
	rgx->result = NULL;
	rgx->size = 0;
	return (rgx);
}

t_fsm		*push_rgx(t_fsm *fsm, t_regex *rgx)
{
	t_regex	*cur;

	cur = fsm->current;
	if (!rgx)
		return (fsm);
	if (!cur)
		fsm->current = rgx;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = rgx;
	}
	return (fsm);
}

int			rgx_len(t_regex *rgx)
{
	int	len;

	len = 0;
	while (rgx)
	{
		len++;
		rgx = rgx->next;
	}
	return (len);
}

int			rgx_result_size(t_regex *rgx)
{
	if ((int)ft_strlen(rgx->result) > rgx->size)
		return (ft_strlen(rgx->result));
	else
		return (rgx->size);
}
