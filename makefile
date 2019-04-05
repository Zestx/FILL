CC = gcc
CFLAGS = -Wall -Wextra -Werror --pedantic 
NAME = fillit
INCLUDES = ./includes/fillit.h
SRCS = ./srcs/*.c
OBJS = fillit.o 

all: $(NAME)

$(NAME): $(OBJS)
	make -C ./libft 
	$(CC) $(CFLAGS) $^ -I. ./libft/libft.a -o fillit 

$(OBJS): $(SRCS)
	$(CC) $(CFLAGS) -I. -c $^

clean:
	rm -rf *.o
	make fclean -C ./libft

fclean: clean
	rm -rf ft_ls

re: fclean all
