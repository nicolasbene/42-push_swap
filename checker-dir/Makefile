SRCDIR = ../src/
OBJDIR = ../bin/
INCDIR = ../include/
FTPATH = ../libft/
FTINC = $(FTPATH)include/
LIBFT = $(FTPATH)libft.a
######################################################################
SRCS = checker/main.c\
		parse.c\
		error.c\
		adv_operations.c\
		checker/operations_bonus.c
OBJS = $(addprefix $(OBJDIR),$(SRCS:.c=.o))
#####################################################################
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3
LINK = -lft 
INCPATH = -I$(INCDIR) -I$(FTINC)
LIBPATH = -L$(FTPATH) 
NAME = checker
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
	#make fclean -C $(FTPATH)
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all libft clean fclean re
