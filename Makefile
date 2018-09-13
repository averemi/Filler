# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrepak <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/13 12:26:27 by nrepak            #+#    #+#              #
#    Updated: 2018/02/13 12:26:31 by nrepak           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = averemii.filler
LIB = libft.a
SRC = ft_filler.c ft_read_map.c ft_clone_map.c ft_make_calc.c ft_algorythm.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@ cd ./libft && make && mv $(LIB) ..
	@ gcc $(OBJ) $(LIB) -Wall -Wextra -Werror -o $(NAME)
	@ gcc -Wall -Werror -Wextra -o bonuspart ft_bonus_part.c $(LIB)
	@ echo "\n"
	@ echo "averemii.filler is ready to start for a FIGHT!"
	@ echo "\n"

%.o: %.c
	@ gcc -Wall -Wextra -Werror -c $<

clean:
	@ /bin/rm -rf $(OBJ)
	@ cd ./libft && make clean

fclean: clean
	@ /bin/rm -f $(NAME)
	@ /bin/rm -f $(LIB)
	@ /bin/rm -f bonuspart
	@ cd ./libft && make fclean
	
re: fclean all
