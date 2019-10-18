/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 22:31:42 by ilian             #+#    #+#             */
/*   Updated: 2018/12/02 15:27:55 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	copy_to_line(char **line, t_list *cur)
{
	int		i;
	char	*tmp;

	i = 0;
	while (((char*)cur->content)[i] != '\0' && ((char*)cur->content)[i] != '\n')
		i++;
	if (((char*)cur->content)[i] == '\n')
	{
		*line = ft_strsub((char*)cur->content, 0, i);
		tmp = ft_strsub((char*)cur->content, i + 1,
			ft_strlen((char*)cur->content));
		free(cur->content);
		cur->content = tmp;
	}
	else if (((char*)cur->content)[i] == '\0')
	{
		*line = ft_strsub((char*)cur->content, 0, i);
		ft_memdel(&cur->content);
		cur->content = ft_strnew(0);
	}
}

int		read_text(const int fd, t_list *cur)
{
	char	buf[BUFF_SIZE + 1];
	int		ret;
	char	*tmp;

	if (!cur->content)
		cur->content = ft_strnew(0);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		tmp = ft_strjoin((char*)cur->content, buf);
		free(cur->content);
		cur->content = tmp;
		if (ft_strchr(buf, '\n'))
			return (ret);
	}
	return (ret);
}

t_list	*get_fd(t_list **data, int fd)
{
	t_list *tmp;
	t_list *created;

	tmp = *data;
	while (tmp)
	{
		if ((int)tmp->content_size == fd)
			return (tmp);
		tmp = tmp->next;
	}
	created = ft_lstnew(NULL, 0);
	created->content_size = fd;
	ft_lstadd(data, created);
	return (created);
}

int		get_next_line(const int fd, char **line)
{
	static t_list	*data;
	t_list			*tmp;
	int				res;

	if (BUFF_SIZE < 1 || fd < 0 || !line)
		return (-1);
	if (!data)
	{
		data = ft_lstnew(NULL, 0);
		data->content_size = fd;
	}
	tmp = get_fd(&data, fd);
	res = read_text(fd, tmp);
	if (res < 0 && (*line = NULL))
		return (-1);
	if (res == 0 && ft_strcmp((char*)tmp->content, "") == 0 && (*line = NULL))
		return (0);
	copy_to_line(line, tmp);
	return (1);
}
