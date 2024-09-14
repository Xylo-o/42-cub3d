NAME := cub3D
CC := gcc
FRAMEWORKS := MLX/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit
FLAGS := -Wall -Wextra -Werror  -Iincludes -Imlx

# PARSING_SRC := parsing/data_parsing.c parsing/file_data.c parsing/file_extension.c parsing/file_parser.c\
# 				parsing/textures_parsing.c 

GNL_SRC := get_next_line/get_next_line.c

LIBFT_SRC := Libft/ft_memset.c Libft/ft_strcmp.c Libft/ft_strdel.c Libft/ft_strdup.c Libft/ft_strjoin.c\
			Libft/ft_strlen.c Libft/ft_strncmp.c Libft/ft_strnew.c Libft/ft_strnstr.c Libft/ft_strrchr.c\
			Libft/ft_strchr.c Libft/ft_strncpy.c  Libft/ft_strlcat.c Libft/ft_strndup.c Libft/ft_memalloc.c\
			Libft/ft_strsub.c Libft/ft_strlcpy.c

SRC := cub3D.c \
		maps/map.c \
		init/init.c \
		render/raycast1.c \
		render/raycast2.c \
		render/raycast3.c \
		controls/key_control1.c \
		controls/key_control2.c \
		utils/utils1.c \

OBJDIR := obj/

OBJ := $(addprefix $(OBJDIR),$(GNL_SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(SRC:.c=.o))

$(OBJDIR)%.o: %.c
	@mkdir -p $(@D)
	@$(CC) $(FLAGS) -c $< -o $@

all: start_compile $(NAME)

bonus: all

start_compile:
	@echo "$(BLUE)Compiling...$(NC)"

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $^ $(FRAMEWORKS) -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJDIR)
	@echo "$(GRAY)Object files cleaned$(NC)"

fclean :
	@rm -rf $(NAME) $(OBJDIR)
	@echo "$(RED)Program files cleaned$(NC)"

re : fclean all

.PHONY: all bonus clean fclean re start_compile

GREEN := \033[0;32m
BLUE := \033[0;34m
GRAY := \033[0;30m
RED := \033[0;31m
NC := \033[0m