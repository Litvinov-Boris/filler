# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svivienn <svivienn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/06 18:44:19 by svivienn          #+#    #+#              #
#    Updated: 2019/09/06 21:42:33 by svivienn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT = libft/libft.a
NAME = svivienn.filler
SRCS =	main.c
SRCO = $(SRCS:.c=.o)
INCLUDES = filler.h

all:$(NAME)

$(LIBFT): 
	make -C libft

$(SRCO): %.o: %.c
	gcc $F -g -c $< -I. -o $@

$(NAME): $(LIBFT) $(SRCO)
	gcc $F -g $(SRCO) -o /Users/svivienn/Downloads/resources/svivienn.filler $(LIBFT)
	chmod 777 /Users/svivienn/Downloads/resources/svivienn.filler

clean:
	rm -f $(SRCO)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C LIBFT fclean
