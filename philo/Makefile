NAME=philo
CC=cc
FLAGS=-Wall -Wextra -Werror
SRC:=philosophers.c utils/time.c
SRC:=$(addprefix sources/, $(SRC))
OBJS=$(SRC:.c=.o)
LIBS=-lpthread

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) $(LIBS) -o $(NAME)

%.o:%.c
	$(CC) $(FLAGS) -I includes/ $< -c -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)

re: fclean all
