# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbouabid <sbouabid@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/03 15:17:41 by sbouabid          #+#    #+#              #
#    Updated: 2024/01/08 17:52:29 by sbouabid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCF 	= ./SRC/main.c ./SRC/parsing1.c ./SRC/utils.c ./SRC/list.c ./SRC/parsing2.c ./SRC/parsing3.c ./SRC/game1.c ./SRC/move.c ./SRC/utils_game.c
GNL		= ./GNL/get_next_line.c ./GNL/get_next_line_utils.c
OBJF_GNL = $(GNL:.c=.o)
OBJF = $(SRCF:.c=.o)
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
CC = cc
MLX_API = -lmlx -framework OpenGL -framework AppKit

NAME = so_long

all: $(NAME)

$(NAME): $(OBJF) $(OBJF_GNL)
	$(CC) $(CFLAGS) $(MLX_API) $(OBJF) $(OBJF_GNL) -o $(NAME)

clean:
	$(RM) $(OBJF) $(OBJF_GNL)

fclean: clean
	$(RM) $(NAME)

re : fclean all
