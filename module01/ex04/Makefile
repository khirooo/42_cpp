NAME	=	replace

CC		=	c++

FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp
OBJS	=	main.o

all: $(NAME)

$(NAME): $(OBJS)
	@echo "compiling ..."
	@$(CC) $(FLAGS) -o $@ $<

%.o:%.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJS)

fclean: clean
	@rm -rf $(NAME)
	@rm -rf infile.txt.replace

re: fclean all

.PHONY: all clean fclean re