/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/03 18:19:19 by ilian             #+#    #+#             */
/*   Updated: 2019/06/03 18:19:20 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	get_type(t_fsm *fsm)
{
	return (fsm->current->format[ft_strlen(fsm->current->format) - 1]);
}

char	*char_to_string(char c)
{
	char	*temp;

	temp = (char*)malloc(2);
	if (temp == NULL)
		return (NULL);
	temp[0] = c;
	temp[1] = '\0';
	return (temp);
}

int		get_size(t_fsm *fsm)
{
	int		size;
	char	*format;
	int		size_c;
	int		doubl;
	int		i;

	format = fsm->current->format;
	size = ft_strlen(format);
	i = 1;
	size_c = 0;
	doubl = 0;
	while (i < size - 1)
	{
		if (size_c > 0 && !doubl && size_c == (int)format[i]
			&& fsm->sizes[size_c * 2] != NULL)
			size_c *= 2;
		else if (fsm->sizes[(int)format[i]] != NULL)
		{
			size_c = (int)format[i];
			doubl = 0;
		}
		i++;
	}
	return (size_c);
}

int		has_asterics_after_digits(char *width)
{
	while (*width && ft_isdigit(*width))
		width++;
	return (*width == '*' ? 1 : 0);
}

char	*ft_strjoinndel(char *s1, char *s2, int del1, int del2)
{
	char *res;

	res = ft_strjoin(s1, s2);
	if (del1)
		FREE(s1);
	if (del2)
		FREE(s2);
	return (res);
}
