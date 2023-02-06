SRCDIR	= src/
OBJDIR	= bin/
INCDIR	= include/
FTPATH	= libft/
FTINC	= $(FTPATH)include/
LIBFT	= $(FTPATH)libft.a
######################################################################
SRCS	= main.c\
			parse.c\
			operations.c\
			adv_operations.c\
			sort_five.c\
			sort_more.c\
			insert_fastest.c\
			median.c\
			error.c

OBJS	= $(addprefix $(OBJDIR),$(SRCS:.c=.o))
#####################################################################
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -g
LINK	= -lft
INCPATH	= -I$(INCDIR) -I$(FTINC)
LIBPATH	= -L$(FTPATH)
NAME	= push_swap
######################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

clean:
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FTPATH)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
