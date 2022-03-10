##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	display.c \
		set_maze_builder.c \
		dante.c \
		list_utils.c


OBJ	=	*.o

NAME =	libmy.a

CPPFLAGS	=	-I ../include/

TESTFILES	=	tests/test_list.c

all: $(NAME) libmaker clean

$(NAME):
	gcc -c $(SRC) $(CPPFLAGS) -g3

libmaker: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	find . -name "*.o" -delete
	rm -f *~

fclean: clean
	$(RM) $(NAME)

re:
	fclean
	$(NAME)
