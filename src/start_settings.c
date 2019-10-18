/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_settings.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:52:24 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 14:52:25 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_field	*read_map(t_field *f, int fd)
{
	char	*line;
	int		read_res;
	int		i;

	i = 0;
	if (!f)
		return (f);
	while ((read_res = get_next_line(fd, &line)) == 1)
	{
		ft_strcpy(f->field[i], line + 4);
		ft_strdel(&line);
		if (i++ == f->size_y - 1)
			break ;
	}
	return (f);
}

t_field	*read_piece(t_field *f, int fd)
{
	int		read_res;
	int		i;
	char	*line;

	i = 0;
	if (!f)
		return (f);
	while ((read_res = get_next_line(fd, &line)) == 1)
	{
		ft_strcpy(f->field[i], line);
		ft_strdel(&line);
		if (i++ == f->size_y - 1)
			break ;
	}
	return (f);
}

t_game	*get_user(t_game *game, int fd)
{
	char	*line;
	int		read_res;

	read_res = get_next_line(fd, &line);
	if (read_res == -1)
		return (NULL);
	if (ft_strstr(line, "$$$ exec p"))
	{
		game = (t_game*)malloc(sizeof(t_game));
		*game = (t_game){(t_field*)malloc(sizeof(t_field)),
		(t_field*)malloc(sizeof(t_field)), ft_strfill(1, line[10]),
		{{1, 0}, {1, 1}, {0, 1}, {-1, 1}, {-1, 0}, {-1, -1}, {0, -1}, {1, -1}}};
		*game->map = (t_field){NULL, NULL, 0, 0, 0};
		*game->piece = (t_field){NULL, NULL, 0, 0, 0};
	}
	ft_strdel(&line);
	return (game);
}

t_game	*get_map(t_game *game, int fd, char *line)
{
	int		i;

	if (game->map->is_filled)
		clear_field(game->map, game->map->size_y);
	else
	{
		game->map->size_x = ft_atoi(ft_strstr(ft_strstr(line, " ") + 1, " "));
		game->map->size_y = ft_atoi(ft_strstr(line, " "));
		game->map->field = (char**)ft_memalloc(game->map->size_y *
			sizeof(char*));
		i = -1;
		while (++i < game->map->size_y)
			game->map->field[i] = (char*)ft_memalloc(game->map->size_x *
				sizeof(char*));
		create_heat_map(game->map);
	}
	get_next_line(fd, &line);
	game->map = read_map(game->map, fd);
	fill_heat_map(game);
	game->map->is_filled = 1;
	ft_strdel(&line);
	return (game);
}

t_game	*get_piece(t_game *game, int fd, char *line)
{
	int		i;

	game->piece->size_x = ft_atoi(ft_strstr(ft_strstr(line, " ") + 1, " "));
	game->piece->size_y = ft_atoi(ft_strstr(line, " "));
	if (game->piece->is_filled)
		clear_field(game->piece, game->map->size_y);
	else
	{
		game->piece->field = (char**)ft_memalloc(game->map->size_y *
			sizeof(char*));
		game->piece->is_filled = 1;
		i = -1;
		while (++i < game->map->size_y)
			game->piece->field[i] = (char*)ft_memalloc(game->map->size_x *
				sizeof(char*));
	}
	game->piece = read_piece(game->piece, fd);
	return (game);
}
