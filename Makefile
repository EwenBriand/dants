##
## EPITECH PROJECT, 2021
## minishell
## File description:
## Makefile
##

SRC	=	dante.c

OBJ	=	$(SRC:.c=.o)

SMAIN	=	main.c

OMAIN	=	$(SMAIN:.c=.o)

NAME	=	dante

CFLAGS	=	-g3

CPPFLAGS	=	-I./include/

#LDFLAGS	= -L ./lib/my/ -lmy

TESTFILES	=

all: $(NAME) unit_tests clean

$(NAME):	$(OBJ) $(OMAIN)
			gcc -o $(NAME) $(OMAIN) $(OBJ) $(CFLAGS)

clean:
	$(RM) $(OBJ) $(OMAIN)
	find . -name "*~" -delete
	find . -name \#* -delete
	find . -name "vgcore*" -delete

fclean:	clean
		$(RM) $(NAME)
		$(RM) unit*

re: fclean all

unit_tests: CPPFLAGS += -lcriterion
unit_tests:
	echo Testing
	gcc -o unit_tests $(SRC) $(TESTFILES) $(CPPFLAGS) $(LDFLAGS) --coverage
	./unit_tests
	gcovr -r .
