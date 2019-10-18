/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 15:00:59 by ilian             #+#    #+#             */
/*   Updated: 2019/06/29 15:01:00 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "libft.h"
# define GAP 3

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_field
{
	char			**field;
	int				**heat_map;
	int				size_x;
	int				size_y;
	int				is_filled;
}					t_field;

typedef struct		s_game
{
	t_field			*map;
	t_field			*piece;
	char			*player;
	int				offsets[8][2];
}					t_game;

/*
**  Global iterators for two-dimension maps
*/

extern t_point		*g_i;
extern t_point		*g_j;

/*
**  Main logical functions
*/

t_game				*get_user(t_game *game, int fd);
t_game				*get_piece(t_game *game, int fd, char *line);
t_game				*get_map(t_game *game, int fd, char *line);
t_point				*place(t_game *game);
void				fill_heat_map(t_game *game);

/*
**  Utilities
*/

int					is_mine(t_game *game, t_point *p);
int					is_enemy(t_game *game, t_point *p);
void				create_heat_map(t_field *map);
t_point				*create_point(int x, int y);
void				copy_point(t_point *from, t_point **to);
void				set_coordinates(t_point *p, int x, int y);
int					is_in_map(t_game *game, t_point *p);
void				clear_field(t_field *map, int size);

#endif
