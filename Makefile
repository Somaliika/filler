NAME = ilian.filler

SRC_DIR = ./src/
OBJ_DIR = ./obj/
INC_DIR = ./inc/

LIB_NAME = ft
LIB_DIR = ./libft
LIB_INC_DIR = $(LIB_DIR)/inc/

CC = gcc
CC_FLAGS = -Wall -Wextra -Werror
DEBUG_FLAGS = #-g3

SRC = main.c start_settings.c place_piece.c cleaning.c heat_map.c utils.c checking.c

OBJCTS = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))


all: $(NAME)

$(NAME): $(OBJCTS)
	@cd $(LIB_DIR) && make
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) $(OBJCTS) -o $(NAME) -I$(INC_DIR) -I$(LIB_INC_DIR) -L$(LIB_DIR) -l$(LIB_NAME)

$(OBJCTS): | $(OBJ_DIR)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CC_FLAGS) $(DEBUG_FLAGS) -c $< -o $@ -I$(INC_DIR) -I$(LIB_INC_DIR)

clean:
	@rm -rf $(OBJ_DIR)
	@cd $(LIB_DIR) && make clean

fclean: clean
	@rm -rf $(NAME)
	@cd $(LIB_DIR) && make fclean

re:	fclean all

vpath %.c $(SRC_DIR)

.PHONY: all clean fclean re
