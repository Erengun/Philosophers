NAME = philo

SRCS = main.c error.c utils.c init.c time.c threading.c

OBJS = $(SRCS:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

TFLAG = -pthread

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(TFLAG) -o $(NAME)

clean: 
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRCS) phil.h