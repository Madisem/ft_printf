# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: maseidua <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/28 15:29:14 by maseidua          #+#    #+#              #
#    Updated: 2019/01/02 19:29:59 by maseidua         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
FLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_addchr.c pt_itoa.c pt_modifiers.c main_func.c ft_fillstr.c ft_fillstart.c
HDR = libftprintf.h
LIB = libft
OBJ = $(SRC:%.c=%.o)

all: $(NAME)

$(NAME): gcc $(FLAGS) -c $(SRC) -I $(HDR)
	@make all -C $(LIB)
##	@cp libft/libft.a ./$(NAME)
	ar rcs $(NAME) $(OBJ)
	ranlib $(NAME)
##	gcc $(FLAGS) $(LIB) -o $(NAME) $(SRC)


clean:
	/bin/rm -f $(OBJ)
	make clean -C $(LIB)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIB)

re: fclean all
