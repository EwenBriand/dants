##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC	=	dante.c	\
		list_utils.c	\
		convert_file/load_file_in_mem.c	\
		convert_file/get_l_and_c_size.c	\
		convert_file/find_j.c	\
		add_neighboors_to_list.c	\

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
