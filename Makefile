NAME := cub3D

CC := gcc

FRAMEWORKS := MLX/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit

FLAGS := -Wall -Wextra -Werror -g #-fsanitize=address

INCLUDE := -Iincludes -Imlx

LIBFT = Libft/libft.a

PARSING_SRC := parsing/parsing.c parsing/parsing_utils.c parsing/error.c\
			parsing/parsing_texture.c parsing/parsing_color.c parsing/parsing_map.c\
			parsing/parsing_floodfill.c parsing/create_map.c

GNL_SRC := get_next_line/get_next_line.c

NEW_SRC := cub3D.c \
		maps/map.c \
		controls/key_control1.c controls/key_control2.c \
		utils/utils1.c utils/utils2.c \
		render/raycast1.c render/raycast2.c render/raycast3.c \
		init/init.c \
		textures/textures.c \

OBJ := $(GNL_SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(NEW_SRC:.c=.o) $(PARSING_SRC:.c=.o)

all: $(LIBFT) $(NAME)

bonus: all

$(NAME) : $(OBJ) $(LIBFT)
	@$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $^ $(FRAMEWORKS) -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C Libft

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean :
	@$(MAKE) -C Libft clean
	@find . -name "*.o" -type f -delete

fclean : clean
	@$(MAKE) -C Libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m