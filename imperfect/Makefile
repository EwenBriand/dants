##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	main.c

PLACE	=	lib/

MY	=	-L lib/

NAME	=	generator

LDFLAGS	=	-I ./include

CFLAGS	=	-g3

all:	dependencies compile clean

make re: fclean all

compile:
	gcc $(SRC) $(MY) -lmy -o $(NAME) $(LDFLAGS)

dependencies:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~

fclean:
	rm -rf *~
	rm -rf *.o
	rm generator
	rm lib/libmy.a
