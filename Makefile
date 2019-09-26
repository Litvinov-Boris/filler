# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:44:19 by svivienn          #+#    #+#              #
#    Updated: 2019/09/26 22:11:51 by svivienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = svivienn.filler
LIBFT = ./libft/libft.a
SRC_DIR = ./src/
OBJ_DIR = ./obj/
SRC_INC_DIR = ./includes/
LIB_INC_DIR = ./libft/
LIB_DIR = ./libft/
SRC_FILES = main.c free.c hot_map.c initialization.c initialization2.c \
	realy_hot_map.c
SRCS = $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o, $(SRCS))
CC = gcc
CFLGS = -Wall -Werror -Wextra
INCL = -I$(SRC_INC_DIR) -I$(LIB_INC_DIR)
LFLGS = -L$(LIB_DIR) -lft

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	$(MAKE) -C libft

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCL) $(LFLGS)
	chmod 777 ./$(NAME)

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(LIB_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean

re: fclean all
