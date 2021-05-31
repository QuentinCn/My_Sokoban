##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## root my_sokoban
##

SRC		=	sources/manage_window.c			\
			sources/move_player.c			\
			sources/o_list.c			\
			sources/get_key.c			\
			sources/end_game.c

SRC_MAIN	=	sources/main.c

SRC_TEST	=	tests/test_sokoban.c

OBJ		= 	${SRC:.c=.o}

OBJ_MAIN 	=	${SRC_MAIN:.c=.o}

NAME		=	my_sokoban

TEST_NAME 	=	unit_test

CFLAGS		= 	-W -Wall -Wextra

UTFLAGS		=	--coverage -lcriterion

CPPFLAGS	= 	-I./include

LDFLAGS		= 	-L./lib -lmy

all:	$(NAME)

libmy:
	make -sC lib/my/
	@echo -e "\033[00m\033[33mlib ready !\033[00m"

test_run: fclean libmy $(OBJ)
	gcc -o $(TEST_NAME) $(CFLAGS) $(SRC_TEST) $(SRC) $(LDFLAGS) $(CPPFLAGS) $(UTFLAGS) -lncurses
	./$(TEST_NAME)
	gcovr

$(NAME): libmy $(OBJ) $(OBJ_MAIN)
	gcc -o $(NAME) -Wall -Wextra $(SRC) $(SRC_MAIN) $(CPPFLAGS) $(LDFLAGS) -lncurses
	@echo -e "\033[00m\033[32mCompilation done => ${NAME}\033[00m"

clean:
	make -sC lib/my/ clean
	rm -f *.gc*
	rm -f $(OBJ)
	rm -f $(OBJ_MAIN)

fclean:	clean
	make -C lib/my/ fclean
	rm -f $(NAME)
	rm -f $(TEST_NAME)
	clear

re:	fclean all

.PHONY:	libmy $(NAME) clean fclean re all
