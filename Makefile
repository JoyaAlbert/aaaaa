SRC				=	get_next_line.c get_next_line_utils.c

OBJ				=	$(SRC:.c=.o)
LIB				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	get_next_line.a

$(NAME):		$(OBJ)
				$(LIB) $(FLAGS) $(NAME) $(OBJ)

all:			$(NAME)

RM				=	rm -f
clean:
				$(RM) $(OBJ)
fclean:			clean
				$(RM) $(NAME)

re:				fclean all

.PHONY: all clean fclean re