NAME	=	animals

CC		=	c++
INCLUDES	=	includes
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -I $(INCLUDES)

SRCDIR	=	src/
SRCFILES = 	Animal.cpp Cat.cpp Dog.cpp WrongAnimal.cpp WrongCat.cpp Brain.cpp
SRCS	=	$(addprefix $(SRCDIR), $(SRCFILES))
SRCS	+= main.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS)
		@echo "Compiling $@"
		@$(CC) $(FLAGS) $(OBJS) -o $@

%.o: %.cpp
	@$(CC) $(FLAGS) -c $< -o $@

clean: 
	@rm -rf $(OBJS)

fclean: clean
		@rm -rf $(NAME)


re: fclean all

.PHONY: all clean fclean re
