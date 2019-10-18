/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilian <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/01 13:13:12 by ilian             #+#    #+#             */
/*   Updated: 2019/06/01 13:13:38 by ilian            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"
# define BUFSIZE 256
# define UPPER 65
# define LOWER 97
# define MAP_SIZE 1000
# define MAX_PREC 4932
# define MAX_WIDTH 2147483645
# define Y 1
# define N 0
# define MAX(x, y) (x >= y ? x : y)
# define MIN(x, y) (x <= y ? x : y)
# define ABS(x)	(((x) < 0) ? -(x) : (x))
# define ISNAN(x) (x != x)
# define ISINF(x) (!ISNAN(x) && ISNAN(x - x))
# define ISZERONEG(x) (ISINF(1 / x) && 1 / x < 0)
# define ROUND(x) ((epsilon(x) >= 0.5) ? (x + 1) : (x))
# define ROUND_TO_EVEN(x) ((int)x % 2) ? (x + 1) : (x)
# define FLAG(c) (ft_strchr("+- #0", c) == NULL ? 0 : 1)
# define POWER_UNSIGN(x, power) ((unsigned long long)to_power_double(x, power))
# define FREE(x) free(x); x = NULL;

typedef struct	s_regex
{
	char			*format;
	long long		width;
	long long		precision;
	char			*result;
	int				i;
	int				done;
	int				size;
	struct s_regex	*next;
}				t_regex;

typedef struct	s_key_func
{
	char				*key;
	void				(*func)();
	struct s_key_func	*next;
}				t_key_func;

typedef struct	s_fsm
{
	void			(*active_state)();
	void			(*update)();
	t_regex			*current;
	va_list			args;
	void			(*types[MAP_SIZE])(struct	s_fsm*);
	long long		(*sizes[MAP_SIZE])(struct	s_fsm*);
	void			(*precisions[MAP_SIZE])(struct	s_fsm*);
	int				error;
}				t_fsm;

void			map_types(t_fsm *fsm);
void			map_sizes(t_fsm *fsm);
void			map_precisions(t_fsm *fsm);

int				ft_printf(const char *format, ...);
t_fsm			*parse(t_fsm *fsm, char *str);
void			keep_asterics(t_fsm *fsm);
void			choose_type(t_fsm *fsm);
void			choose_width(t_fsm *fsm);
void			choose_precision(t_fsm *fsm);

void			type_int(t_fsm *fsm);
void			type_int_unsigned(t_fsm *fsm);
void			type_octal_int(t_fsm *fsm);
void			type_hex_int_l(t_fsm *fsm);
void			type_hex_int_s(t_fsm *fsm);
void			type_float(t_fsm *fsm);
void			type_char(t_fsm *fsm);
void			type_string(t_fsm *fsm);
void			type_pointer(t_fsm *fsm);
void			type_percent(t_fsm *fsm);
void			type_wrong(t_fsm *fsm);

long long		size_long_int(t_fsm *fsm);
long long		size_signed_char(t_fsm *fsm);
long long		size_long_long(t_fsm *fsm);
long long		size_short_int(t_fsm *fsm);

void			precision_int(t_fsm *fsm);
void			precision_float(t_fsm *fsm);
void			precision_string(t_fsm *fsm);
void			precision_pointer(t_fsm *fsm);

void			flag_minus(t_fsm *fsm);
void			flag_plus(t_fsm *fsm);
void			flag_space(t_fsm *fsm);
void			flag_octotorp(t_fsm *fsm);
void			flag_zero(t_fsm *fsm);
void			flags_hex_int(t_fsm *fsm);

void			expand_right(t_fsm *fsm);
void			expand_left(t_fsm *fsm);

char			*ft_itoa_base_unsigned(unsigned long long nbr,
	int base, int type);
char			*ft_itoa_decimal(long long nbr);
int				digit_count(long double n, int base);
char			*float_to_string(long double f, long long prec);
char			*char_to_string(char c);
int				has_flag(char *format, char c);
void			push_map_item(t_key_func *map, char *key, void (*func)());
t_key_func		*create_map(char *key, void (*func)());
t_regex			*create_rgx(char *format, int i, int save_format);
t_fsm			*push_rgx(t_fsm *fsm, t_regex *rgx);
int				rgx_len(t_regex *rgx);
int				is_regex(char *str, t_fsm *fsm);
t_regex			*buffercat(t_regex *buffer, t_regex *rgx);
int				skip_digits(char *str, int i);
int				rgx_result_size(t_regex *rgx);
char			get_type(t_fsm *fsm);
int				has_asterics_after_digits(char *width);
int				get_size(t_fsm *fsm);
int				is_bad_float(char *result);
t_regex			*create_buffer();
int				is_overflow(t_regex *buffer, t_regex *rgx);
char			*ft_strjoinndel(char *s1, char *s2, int del1, int del2);
void			clear_list(t_regex	*r);
long double		epsilon(long double num);
char			*ft_itoa_base_double(long double nbr);
long double		to_power_double(long double nbr, int power);
void			track_error(t_fsm *fsm);

#endif
