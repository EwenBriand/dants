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

all:	oui compile clean

compile:
	gcc $(SRC) $(MY) -lmy -o $(NAME)

oui:
	$(MAKE) -C $(PLACE)

clean:
	rm -rf *~
