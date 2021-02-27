NAME = libprintf.lib
SRCS =	./ft_printf.c\
		./input_parser.c\
		./str_modification.c\
		./special_functions.c\
		./put_functions.c
OBJS = $(SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(SRCS)
	@gcc -c $(SRCS) $(FLAGS) -I ../libft
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "$(NAME) was successfully created."

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: clean, all, re, fclean
