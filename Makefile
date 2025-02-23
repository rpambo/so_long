NAME		=	so_long
CC			=	cc
FLAGS		=	-Wall -Wextra -Werror -no-pie
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./srcs -I ./libft -I ./mlx
LIB			=	-L ./libft -lft -L ./mlx -lmlx -lX11 -lXext -lm
OBJ			=	$(SRC:.c=.o)
GREEN		=	\033[0;32m
RED 		=	\033[0;31m
YELLOW		=	\033[0;33m
RESET		=	\033[0m
SRC			=  srcs/so_long.c srcs/ulils.c srcs/destroy_root.c srcs/so_long_init.c \
				srcs/file_reader.c  srcs/map_parser.c  \
				srcs/map_is_valid.c srcs/map_builder.c srcs/print_map.c \
				srcs/renderization.c srcs/renderization.c srcs/graphics.c \
				srcs/events.c srcs/move.c

all:		$(MLX) $(LFT) $(NAME)

$(NAME):	$(OBJ)
			@echo "$(RED)[ .. ] Compiling Mandatory..$(RESET)"
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Mandatory Ready!$(RESET)"

$(MLX):
			@echo "$(RED)[ .. ] | Compiling minilibx..$(RESET)"
			@make -s -C mlx
			@echo "$(GREEN)[ OK ]$(RESET)|$(YELLOW)Minilibx ready!$(RESET)"

$(LFT):
			@echo "$(RED)[ .. ] Compiling Libft..$(RESET)"
			@make -s -C libft
			@echo "$(GREEN)[ OK ]$(RESET) $(YELLOW)Libft ready!$(RESET)"

srcs/%.o:	srcs/%.c
			@$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) srcs/*.o
			@echo "Object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "Binary file removed."

re:			fclean all

.PHONY:		all clean fclean re
