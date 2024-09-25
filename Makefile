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
		init/init.c \
		render/raycast1.c \
		render/raycast2.c \
		render/raycast3.c \
		controls/key_control1.c \
		controls/key_control2.c \

OBJDIR := obj/

OBJ := $(addprefix $(OBJDIR),$(GNL_SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(SRC:.c=.o))

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

all: $(LIBFT) $(NAME)

bonus: all

start_compile:
	@echo "$(BLUE)Compiling...$(NC)"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ $(FRAMEWORKS) -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C Libft

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)Object files cleaned$(NC)"

fclean :
	@rm -rf $(NAME) $(OBJDIR)
	@echo "$(RED)Program files cleaned$(NC)"

re : fclean all

.PHONY: all bonus clean fclean re

GREEN := \033[0;32m
BLUE := \033[0;34m
GRAY := \033[0;30m
RED := \033[0;31m
NC := \033[0m