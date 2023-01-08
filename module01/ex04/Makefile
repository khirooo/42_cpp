NAME	=	replace

CC		=	g++

FLAGS	=	-Wall -Wextra -Werror -std=c++98
SRC		=	main.cpp


all: $(NAME)

$(NAME): $(SRC)
	@echo "compiling ..."
	@$(CC) $(FLAGS) -o $@ $<


clean:
	@rm -rf $(NAME)
	@rm -rf infile.txt.replace

flcean: 
	clean

re: fclean all

.PHONY: all clean fclean re