# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rpambo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/23 17:56:18 by rpambo            #+#    #+#              #
#    Updated: 2025/02/23 17:56:22 by rpambo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	so_long
BONU_NAME	=	so_long_bonus
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX			=	mlx/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./srcs -I ./libft -I ./mlx
LIB = ./libft/*.o -L ./mlx -lmlx -lX11 -lXext -lm
OBJ			=	$(SRC:.c=.o)
OBJ_BONUS	= 	$(SRCBUNS:.c=.o)

SRC			= 	srcs/so_long.c \
			   srcs/ulils.c \
			   srcs/destroy_root.c \
			   srcs/so_long_init.c \
			   srcs/file_reader.c  \
			   srcs/map_parser.c  \
			   srcs/map_is_valid.c \
			   srcs/map_builder.c \
			   srcs/print_map.c \
			   srcs/renderization.c \
			   srcs/graphics.c \
			   srcs/events.c \
			   srcs/move.c \
			   srcs/error.c

SRCBUNS			= bonus/srcs/so_long_bonus.c \
			  bonus/srcs/ulils_bonus.c \
			  bonus/srcs/destroy_root_bonus.c \
			  bonus/srcs/so_long_init_bonus.c \
			  bonus/srcs/file_reader_bonus.c \
			  bonus/srcs/map_parser_bonus.c  \
			  bonus/srcs/map_is_valid_bonus.c \
			  bonus/srcs/map_builder_bonus.c \
			  bonus/srcs/print_map_bonus.c \
			  bonus/srcs/renderization_bonus.c \
			  bonus/srcs/graphics_bonus.c \
			  bonus/srcs/events_bonus.c \
			  bonus/srcs/move_bonus.c \
			  bonus/srcs/move_enemy_bonus.c \
			  bonus/srcs/store_positions.c \
			  bonus/srcs/display_moviment.c \
			  bonus/srcs/error.c \
			  bonus/srcs/allocate_game_resource_bonus.c

all:		$(MLX) $(LFT) $(NAME)

bonus: $(MLX) $(LFT) $(BONU_NAME)

$(NAME):	$(OBJ)
			@echo "Compiling Mandatory.."
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "Mandatory Ready!"

$(BONU_NAME):	 $(OBJ_BONUS)
			@echo "Compiling Bonus.."
			@$(CC) $(FLAGS) -o $@ $^ $(LIB)
			@echo "Bonus Ready!"

$(MLX):
			@echo "Compiling MiniLibX.."
			@make -s -C mlx
			@echo "MiniLibX ready!"

$(LFT):
			@echo "Compiling Libft.."
			@make -s -C libft
			@echo "Libft ready!"

srcs/%.o:	srcs/%.c
			@$(CC) $(FLAGS) $(INC) -c $< -o $@

bonus/srcs/%.o: bonus/srcs/%.c
			@$(CC) $(FLAGS) $(INC) -c $< -o $@

clean:
			@make -s clean -C libft
			@rm -rf $(OBJ) $(OBJ_BONUS)
			@echo "Object files removed."

fclean:		clean
			@make -s fclean -C libft
			@rm -rf $(NAME) $(BONU_NAME)
			@echo "Binary files removed."

re:			fclean all

.PHONY:		all clean fclean re
