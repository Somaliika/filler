/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 16:52:37 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 16:52:38 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
**    Recursive function that check starting part for being regex.
**    Then cuts and saves it to fsm.
**    If string does not seam to be a regex
**    so it searches for next '%' and cut till that symbol.
**    If there is no '%', so save it whole to regex.
*/

t_fsm	*parse(t_fsm *fsm, char *str)
{
	int		len;
	t_regex	*rgx;
	char	*sub;

	if (!fsm || !str || ft_strlen(str) == 0)
		return (fsm);
	len = is_regex(str, fsm);
	if (len == -1)
	{
		len = ft_strchri(str, '%');
		if (len == -1)
			rgx = create_rgx(str, rgx_len(fsm->current) + 1, N);
		else
			rgx = create_rgx(ft_strsub(str, 0, len),
				rgx_len(fsm->current) + 1, Y);
	}
	else
		rgx = create_rgx(ft_strsub(str, 0, len), rgx_len(fsm->current) + 1, Y);
	push_rgx(fsm, rgx);
	if (len == -1 || ft_strlen(str) - len == 0)
		sub = NULL;
	else
		sub = ft_strsub(str, len, ft_strlen(str) - len);
	FREE(str);
	return (parse(fsm, sub));
}

/*
**    Checks whether all element of formating are placed well.
**    If OK - send index where regex ends in string. If not - returns -1.
*/

int		is_regex(char *str, t_fsm *fsm)
{
	int i;

	i = 1;
	if (str[0] != '%')
		return (-1);
	while (FLAG(str[i]) || ft_isdigit(str[i]) || str[i] == '.' ||
		str[i] == '*' || fsm->sizes[(int)str[i]])
		i++;
	return (++i);
}

int		skip_digits(char *str, int i)
{
	if (str[i] == '*')
		return (++i);
	while (ft_isdigit(str[i]))
		i++;
	return (i);
}
