NAME	=	span

CC		=	c++
INCLUDES =	./
FLAGS	=	 -Wall -Wextra -Werror -std=c++98 -I $(INCLUDES)

HEADER	=	Span.hpp
SRCDIR	=	./
SRCFILES = 	Span.cpp
SRCS	=	$(addprefix $(SRCDIR), $(SRCFILES))
SRCS	+= main.cpp

OBJS	=	$(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS) $(HEADER)
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
