##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefilep
##

SRC	=	eller.c \
		set_maze_builder.c

OBJ	=	*.o

NAME =	libmy.a

CPPFLAGS	=	-I ../include/

all: $(NAME) libmaker clean

$(NAME):
	gcc -c $(SRC) $(CPPFLAGS) -g3

libmaker: $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f *.o
	rm -f *~

fclean:
	clean
	$(RM) $(NAME)
