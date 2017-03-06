#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jde-maga <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/20 13:50:50 by jde-maga          #+#    #+#              #
#    Updated: 2016/07/21 19:59:22 by jde-maga         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

SRC_PATH = src/
SRC_NAME = main.c parser.c lemin_struct_parser.c parser_room.c parser_tube.c path_verify.c solver.c ant_pusher.c display_data.c number_of_rooms.c int_array_init.c solver_operations.c solver_path.c solver_reach.c solver_steps.c duplicate_tube.c room_syntax_error.c ant_pusher_room_op.c ant_pusher_path_op.c ptr_list.c
OBJ_PATH = obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I./includes
NAME = lem-in
SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
LIBS = libft/libft.a

all : $(NAME)

$(NAME) : $(OBJ)
		$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		@mkdir $(OBJ_PATH) 2> /dev/null || true
		$(CC) -c $(CFLAGS) $< -o $@

clean :
		rm -rf $(OBJ_PATH)

fclean : clean
		rm -rf $(NAME)

re : fclean all
