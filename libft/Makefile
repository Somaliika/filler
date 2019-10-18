NAME = libft.a

SRC = ft_atoi.c ft_atoli.c ft_bzero.c ft_chrswap.c ft_isallequal.c ft_isalnum.c ft_isalpha.c\
ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c\
ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c\
ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putchar.c\
ft_putendl_fd.c ft_putendl.c ft_putnbr_fd.c ft_putnbr.c ft_putstr_fd.c \
ft_putnstr.c ft_putstr.c ft_sort.c\
ft_strarcat.c ft_strcat.c ft_strchr.c ft_strchri.c ft_strclr.c ft_strcmp.c ft_strcpy.c\
ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c\
ft_strjoin.c ft_strnjoin.c\
ft_strlcat.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c\
ft_strncpy.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strrchri.c\
ft_strrev.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c\
ft_strfill.c\
ft_swap.c ft_tolower.c ft_topower.c ft_tosentence.c ft_toupper.c \
get_next_line.c \
pt_buffer.c ft_printf.c pt_flag_zero.c pt_flags_utils.c pt_flags.c \
pt_itoa_base.c pt_maps.c pt_modificators.c pt_parsing.c\
pt_precisions.c pt_regex.c pt_sizes.c pt_types_general.c pt_types_int.c pt_types_float.c pt_utils.c

OBJCTS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = #-g3

all: $(NAME)

$(NAME): $(OBJCTS)
	@ar rc $(NAME) $(OBJCTS)
	@ranlib $(NAME)
	
$(OBJCTS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.c
	@$(CC) $(DEBUG_FLAGS) $(CC_FLAGS) -c $< -o $@ -I$(INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re:	fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
