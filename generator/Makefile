##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	main.c

PLACE	=	lib/

MY	=	-L ./lib/

NAME	=	generator

CPPFLAGS	=	-I ./include

CFLAGS	=	-g3

all:	dependencies compile clean

make re: fclean all

compile:
	gcc $(SRC) $(MY) -lmy $(CPPFLAGS) -o $(NAME)

dependencies:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~

fclean:
	rm -rf *~
	rm -rf *.o
	rm -f generator
	rm -f lib/libmy.a
