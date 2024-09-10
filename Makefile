NAME := cub3D

CC := gcc

FRAMEWORKS := MLX/libmlx42.a -lglfw -framework Cocoa -framework OpenGL -framework IOKit

FLAGS := -Wall -Wextra -Werror -g #-fsanitize=address

INCLUDE := -Iincludes -Imlx

# PARSING_SRC := parsing/data_parsing.c parsing/file_data.c parsing/file_extension.c parsing/file_parser.c\
# 				parsing/textures_parsing.c 

PARSING_SRC := parsing/parsing.c parsing/parsing_utils.c parsing/error.c parsing/parsing_texture.c parsing/parsing_color.c

GNL_SRC := get_next_line/get_next_line.c

LIBFT_SRC := Libft/ft_memset.c Libft/ft_strcmp.c Libft/ft_strdel.c Libft/ft_strdup.c Libft/ft_strjoin.c\
			Libft/ft_strlen.c Libft/ft_strncmp.c Libft/ft_strnew.c Libft/ft_strnstr.c Libft/ft_strrchr.c\
			Libft/ft_strchr.c Libft/ft_strncpy.c Libft/ft_strlcat.c Libft/ft_strndup.c Libft/ft_memalloc.c\
			Libft/ft_strsub.c Libft/ft_strlcpy.c Libft/ft_substr.c Libft/ft_calloc.c Libft/ft_bzero.c\
			Libft/ft_strtrim.c Libft/ft_isspace.c Libft/ft_atoi.c Libft/ft_isdigit.c

NEW_SRC := cub3D.c \
		maps/map.c \
		controls/key_control1.c \
		controls/key_control2.c \
		utils/utils1.c \
		render/raycast1.c \
		render/raycast2.c \
		render/raycast3.c \
		init/init.c \
		utils/utils2.c \
		textures/textures.c \

OBJ := $(GNL_SRC:.c=.o) $(LIBFT_SRC:.c=.o) $(NEW_SRC:.c=.o) $(PARSING_SRC:.c=.o)

all: $(NAME)

bonus: all

start_compile:
	@echo "Compiling..."

$(NAME) : $(OBJ)
	@$(CC) $(FLAGS) $(INCLUDE) $^ $(FRAMEWORKS) -o $@
	@echo "$(GREEN)Compiled successfully$(NC)"

%.o: %.c
	@$(CC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean :
	@find . -name "*.o" -type f -delete

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all bonus clean fclean re start_compile

GREEN := \033[0;32m
BLUE := \033[0;34m
NC := \033[0m