##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## bonus my_sokoban
##

SRC	=	$(shell find -name "*.c")	\
		../sources/end_game.c		\
		../sources/get_key.c		\
		../sources/move_player.c	\
		../sources/o_list.c

NAME	=	my_sokoban_bonus

CSFML   =       -lcsfml-graphics -lcsfml-window -lcsfml-system -lcsfml-audio

all:	$(NAME)

libmy:
	@make -sC ../lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) -Wall -Wextra $(SRC) -L./../lib -lmy -I./../include -lncurses $(CSFML)
	@echo -e "\033[05m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	@make -sC ../lib/my/ clean
	@rm -f *~ ../include/*~ ../lib/my/*~

fclean:	clean
	make -C ../lib/my/ fclean
	rm -f $(NAME)
	clear

re:	fclean all

.PHONY:	libmy $(NAME) clean fclean re all
