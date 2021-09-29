NAME = philo
CC = gcc
INC = -I 
SRCS =	philo.c  help.c philo2.c
FLAGS = -Wall -Wextra -Werror
OBJS = $(SRC:.c=.o)
all: $(NAME)
$(NAME):
	@$(CC) $(FLAGS) $(SRCS) -o $(NAME) 
clean:

fclean: clean
	@rm -f $(NAME)
re : fclean $(NAME)