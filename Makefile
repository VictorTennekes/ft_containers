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

SHELL		=	/bin/sh
.SUFFIXES	=	
.SUFFIXES	=	.cpp .o

NAME		=	containers
CONTAINERS	=	list vector map stack queue
SRC			:=	$(foreach src, $(CONTAINERS), tests/test_$(src).cpp)
OBJ			:=	$(SRC:tests/%.cpp=tests/%.o)
CFLAGS		=	-Wall -Wextra -Werror -pedantic -std=c++98
CC			=	clang++
INCL		:=	$(CONTAINERS:%=-I ./%)

CONTAINERS	:= $(CONTAINERS:%=test_%)

# COLORS
WHITE   = \x1b[37;01m
RESET   = \x1b[0m

ifeq ($(DEBUG), 1)
	CFLAGS += -g -fsanitize=address
else ifeq ($(RELEASE), 1)
	CFLAGS += -O3
endif

ifeq ($(STD), 1)
	CFLAGS += -D STD_TEST
endif

all: $(CONTAINERS)

tests/%.o: tests/%.cpp
	$(CC) -c $(CFLAGS) -I iterators -I traits -I utils -I tests $(INCL) $< -o $@

.SECONDEXPANSION:
$(CONTAINERS) : tests/$$@.o
	@echo "$(WHITE)/-----    Compiling $@     	-----\\ $(RESET)"
	$(CC) $(CFLAGS) $(INCL) -I iterators -I traits -I utils -I tests tests/$@.o -o $@

clean:
	@echo "$(WHITE)/-----    Cleaning $(NAME)        	-----\\ $(RESET)"
	rm -f $(OBJ)

fclean: clean
	@echo "$(WHITE)/-----    Fcleaning $(NAME)        	-----\\ $(RESET)"
	rm -f $(CONTAINERS:%=%)

re:	fclean all

.PHONY:	all clean fclean re
