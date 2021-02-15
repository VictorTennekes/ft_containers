# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: vtenneke <vtenneke@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/27 16:08:22 by vtenneke      #+#    #+#                  #
#    Updated: 2021/01/27 16:08:22 by vtenneke      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME		=	containers
SRC			=	test_list
OBJ			=	$(SRC:%.cpp=%.o)
CPPFLAGS	=	-Wall -Wextra -Werror -pedantic -ansi -std=c++98
# CPPFLAGS	=
CPP			=	clang++

# CONTAINERS
CONTAINERS = list

# COLORS
WHITE   = \x1b[37;01m
RESET   = \x1b[0m

ifeq ($(DEBUG), 1)
	CPPFLAGS += -g -fsanitize=address
else ifeq ($(RELEASE), 1)
	CPPFLAGS += -O3
endif

ifeq ($(STD), 1)
	CPPFLAGS += -D STD_TEST
endif

all: $(CONTAINERS)

$(CONTAINERS):
	@echo "$(WHITE)/-----    Cleaning $(NAME)_$@     -----\\ $(RESET)"
	$(CPP) $(CPPFLAGS) tests/test_$@.cpp -o test_$@ -I iterators -I traits -I utils -I tests -I $@

clean:
	@echo "$(WHITE)/-----    Cleaning $(NAME)        -----\\ $(RESET)"

fclean: clean
	@echo "$(WHITE)/-----    Fcleaning $(NAME)        -----\\ $(RESET)"
	rm -rf $(CONTAINERS:%=test_%) $(CONTAINERS:%=test_%.dSYM)

re:	fclean all

.PHONY:	all clean fclean re $(CONTAINERS)