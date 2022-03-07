##
## EPITECH PROJECT, 2021
## Project Name
## File description:
## my Makefile
##

SRC	=	main.c

PLACE	=	lib/

MY	=	-L lib/

NAME	=	solver

all:	dependencies compile clean

compile:
	gcc $(SRC) $(MY) -lmy -o $(NAME)

dependencies:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~
