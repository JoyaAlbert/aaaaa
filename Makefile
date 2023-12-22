SRC				=	get_next_line.c get_next_line_utils.c
BONUS_SRC		=	get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ				=	$(SRC:.c=.o)
OBJ_BONUS		=	$(BONUS_SRC:.c=.o)
LIB				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	get_next_line.a

$(NAME):		$(OBJ)
				$(LIB) $(FLAGS) $(NAME) $(OBJ)

all:			$(NAME)

RM				=	rm -f
clean:
				$(RM) $(OBJ) $(OBJ_BONUS)
fclean:			clean
				$(RM) $(NAME)
bonus:			$(OBJ_BONUS)
re:				fclean all

.PHONY: all clean fclean re