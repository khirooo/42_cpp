NAME	=	megaphone

CC		=	g++
FLAGS	=	-Wall -Wextra -Werror -std=c++98

SRCDIR	=	.
SRCS	=	megaphone.cpp

all: $(NAME)

$(NAME): $(SRCDIR)/$(SRCS)
		@echo "Compiling $@"
		@(CC) $(FLAGS) -o $@ $^

clean: 

fclean: clean
		@rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re

