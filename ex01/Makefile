# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amak <amak@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 23:39:18 by amak              #+#    #+#              #
#    Updated: 2024/06/19 23:39:36 by amak             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FormUpMmaggots

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SOURCES =	Bureaucrat.cpp \
			Form.cpp \
			main.cpp
			
OBJECTS = $(SOURCES:.cpp=.o)

all: $(NAME)
	
$(NAME): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(NAME)
	
clean:
	@rm -f $(OBJECTS)
	@echo Deleted object files!

fclean: clean
	@rm -f $(NAME)
	@echo Deleted executable!

re: fclean all

.PHONY: all bonus clean fclean re