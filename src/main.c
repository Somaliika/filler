/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 18:57:20 by ilian             #+#    #+#             */
/*   Updated: 2019/06/28 18:57:22 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_point		*g_i;
t_point		*g_j;

void	loop(t_game *game, int fd)
{
	char	*line;
	int		read_res;
	int		i;
	t_point	*move;

	i = 0;
	while ((read_res = get_next_line(fd, &line)) == 1 &&
		line && ft_strlen(line) > 0)
	{
		if (ft_strstr(line, "Plateau"))
			game = get_map(game, fd, line);
		else if (ft_strstr(line, "Piece"))
		{
			game = get_piece(game, fd, line);
			if (game->map->is_filled)
			{
				move = place(game);
				move ? ft_printf("%d %d\n", move->y, move->x) :
					ft_printf("0 0\n");
				FREE(move);
			}
		}
		ft_strdel(&line);
	}
	ft_strdel(&line);
}

/*
**  Launching with command:
**  ./filler_vm -p1 ./ilian.filler -p2 players/carli.filler -v -f maps/map00
*/

int		main(void)
{
	t_game	*game;
	int		fd;

	fd = 0;
	game = NULL;
	g_i = create_point(0, 0);
	g_j = create_point(0, 0);
	game = get_user(game, fd);
	if (!game)
		return (0);
	loop(game, fd);
	return (0);
}
