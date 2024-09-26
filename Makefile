NAME := cub3D
CC := cc
FRAMEWORKS := -lglfw -framework Cocoa -framework OpenGL -framework IOKit

FLAGS := -Wall -Wextra -Werror -g #-fsanitize=address

INCLUDE := -Iincludes -Imlx

LIBFT = Libft/libft.a
LIBMLX := MLX42
MLX_LIB := $(LIBMLX)/build/libmlx42.a

PARSING_SRC := parsing/parsing.c parsing/parsing_utils.c parsing/error.c\
			parsing/parsing_texture.c parsing/parsing_color.c parsing/parsing_map.c\
			parsing/parsing_floodfill.c parsing/create_map.c

GNL_SRC := get_next_line/get_next_line.c

SRC := cub3D.c \
		init/init.c \
		render/raycast1.c \
		render/raycast2.c \
		render/raycast3.c \
		controls/key_control1.c \
		controls/key_control2.c \

OBJDIR := obj/

OBJ := $(addprefix $(OBJDIR),$(GNL_SRC:.c=.o) $(SRC:.c=.o) $(PARSING_SRC:.c=.o))

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -I $(LIBMLX)/include -c $< -o $@

all: $(LIBFT) $(MLX_LIB) $(NAME)

bonus: all

start_compile:
	@echo "$(BLUE)Compiling...$(NC)"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDE) $(LIBFT) $(MLX_LIB) $^ $(FRAMEWORKS) -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

$(LIBFT):
	@$(MAKE) -C Libft

$(MLX_LIB):
	@git clone https://github.com/codam-coding-college/MLX42.git $(LIBMLX)
	@cmake $(LIBMLX) -B $(LIBMLX)/build
	@cmake --build $(LIBMLX)/build -j4

clean :
	@$(MAKE) -C Libft clean
	@rm -rf $(OBJDIR) 
	@echo "$(GRAY)Object files cleaned$(NC)"

fclean : clean
	@$(MAKE) -C Libft fclean
	@rm -rf $(NAME) $(LIBMLX)
	@echo "$(RED)Program files cleaned$(NC)"

# clean :
# 	@$(MAKE) -C Libft clean
# 	@find . -name "*.o" -type f -delete

# fclean : clean
# 	@$(MAKE) -C Libft fclean
# 	@rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re

GREEN := \033[0;32m
BLUE := \033[0;34m
GRAY := \033[0;30m
RED := \033[0;31m
NC := \033[0m