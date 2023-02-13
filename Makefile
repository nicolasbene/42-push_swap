SRCDIR = src/
OBJDIR = bin/
INCDIR = include/
FTPATH = libft/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
######################################################################
SRCS = main.c\
		parse.c\
		error.c\
		sort_five.c\
		adv_operations.c\
		operations.c\
		sort_more.c\
		insert_fastest.c\
		median.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
#####################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LINK = -lft
INCPATH = -I$(INCDIR) -I$(FTINC)
LIBPATH = -L$(FTPATH)
NAME = push_swap
######################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(OBJS) $(LIBPATH) $(LINK) -o $(NAME)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) -c $(CFLAGS) $(INCPATH) $< -o $@

$(LIBFT):
	make -C $(FTPATH)

checker:
	make -C checker-dir/
	cp checker-dir/checker .

clean:
	rm -rf $(OBJS)

fclean: clean
	make fclean -C $(FTPATH)
	rm -f $(NAME)
	rm -f checker

re: fclean $(NAME)

.PHONY: all libft clean fclean re
