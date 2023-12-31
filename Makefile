SRC				=	get_next_line.c get_next_line_utils.c
BONUS_SRC		=	get_next_line_bonus.c get_next_line_utils_bonus.c
OBJ				=	$(SRC:.c=.o)
OBJ_BONUS		=	$(BONUS_SRC:.c=.o)
LIB				=	ar rcs
CFLAGS			=	-Wall -Wextra -Werror
NAME			=	get_next_line.a

CLR_RMV		:= \033[0m
RED		    := \033[1;31m
GREEN		:= \033[1;32m
YELLOW		:= \033[1;33m
BLUE		:= \033[1;34m
CYAN 		:= \033[1;36m

$(NAME):		$(OBJ)
				@echo "$(GREEN)Compilation ${CLR_RMV}of ${YELLOW}$(NAME) ${CYAN}"
				$(LIB) $(FLAGS) $(NAME) $(OBJ)


all:			$(NAME)

RM				=	rm -f
clean:
				@echo "$(RED)Deleting ${YELLOW}.o ${CLR_RMV}"
				$(RM) $(OBJ) $(OBJ_BONUS)
fclean:			clean
				@echo "$(RED)Deleting ${YELLOW}.a ${CLR_RMV}"
				$(RM) $(NAME)
bonus:			$(OBJ_BONUS)
re:				fclean all

.PHONY: all clean fclean re