NAME	=	harl

CC		=	g++
INCLUDES	=	includes
FLAGS	=	-Wall -Wextra -Werror -std=c++98 -I $(INCLUDES)

SRCDIR	=	./
SRCFILES = 	Harl.cpp main.cpp
SRCS	=	$(addprefix $(SRCDIR), $(SRCFILES))

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
