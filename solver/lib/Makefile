##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	*.c

ALLGCC	=	*.o

NAME	=	libmy.a

MY	=	../../my.h

DEST	=	../../include/

all:	obj libmaker right clean

libmaker:
	ar rc $(NAME) $(ALLGCC)

obj:
	gcc -c $(SRC)

right:
	chmod 777 $(NAME)

clean:
	rm -f *.o
	rm -f *~

copy:
	cp $(MY) $(DEST)
