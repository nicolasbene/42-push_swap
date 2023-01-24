NAME	=	push_swap

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror -g3

SRC		=	main.c\
			errors.c\
			exit.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

all:	obj $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	@$(CC) $(FLAGS) -Iinclude/ -o $@ -c $<

$(NAME):	$(OBJ)
	@$(CC) $(FLAG) $(OBJ) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@echo "OBJ deleted"

fclean:	clean
	@rm -rf $(NAME)
	@echo "$(NAME) deleted"

re:	fclean all

.PHONY:	all, clean, fclean, re
