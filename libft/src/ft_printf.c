/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:28:52 by ilian             #+#    #+#             */
/*   Updated: 2019/06/27 18:39:23 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	update(t_fsm *fsm)
{
	void	(*f)();

	f = fsm->active_state;
	if (fsm->active_state != NULL)
		f(fsm);
}

int		finishing(t_regex **buffer, t_fsm **fsm, t_regex *backup)
{
	clear_list(backup);
	FREE(*fsm);
	clear_list(*buffer);
	return (1);
}

void	preparing(t_regex **buffer, t_fsm **fsm)
{
	*buffer = create_buffer();
	(*buffer)->width = 0;
	*fsm = (t_fsm*)malloc(sizeof(t_fsm));
	ft_bzero(*fsm, sizeof(t_fsm));
	(*fsm)->update = update;
	(*fsm)->error = 0;
	map_types(*fsm);
	map_sizes(*fsm);
	map_precisions(*fsm);
}

/*
**  Printf works on basis of finite-state machine (FSM).
**
**  All guidelines for proceessing data,
**	maps of functions according to type, size and so on stores in fsm object.
**
**  Function starts from parsing in list of regex and save in fsm,
**	then process each regex and saves result in buffer.
**	Its size is current length and width is accumulated length.
**	When the buffer is full it prints to stdout.
**
**  The function to be done next stores in fsm->active_state.
**	To receive result of regex it takes start point - keep_asterics.
**	And in loop call active_state until regex will be done.
*/

int		ft_printf(const char *format, ...)
{
	t_regex		*buffer;
	t_fsm		*fsm;
	t_regex		*backup;
	int			result;

	if (!format)
		return (0);
	preparing(&buffer, &fsm);
	va_start(fsm->args, format);
	parse(fsm, ft_strdup(format));
	backup = fsm->current;
	while (fsm->current && !fsm->error)
	{
		fsm->active_state = keep_asterics;
		while (!fsm->current->done && !fsm->error)
			(*fsm->update)(fsm);
		if (fsm->error && finishing(&buffer, &fsm, backup))
			return (-1);
		buffercat(buffer, fsm->current);
		fsm->current = fsm->current->next;
	}
	result = buffer->width;
	ft_putnstr(buffer->result, buffer->size);
	finishing(&buffer, &fsm, backup);
	return (result);
}
