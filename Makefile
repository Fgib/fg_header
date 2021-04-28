NAME =	unknown_printer_for_the_yeet

SRC =	src/header_creator.c\

OBJ =	$(SRC:.c=.o)

CFLAGS= $(INC)	\
	-W	\
	-Wall	\
	-Wextra	\

CC =	gcc

RULE =	all

all:    $(NAME)


$(NAME):$(OBJ)
	$(CC) -o $(NAME) $(OBJ)
	@ mv $(NAME) ./src

clean:
	$(RM) $(OBJ)

fclean:	clean
	$(RM) ./src/$(NAME)

re:	fclean all

.PHONY: all clean fclean re