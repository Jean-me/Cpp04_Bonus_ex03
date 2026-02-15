# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: haatwata <haatwata@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/30 16:07:27 by haatwata          #+#    #+#              #
#    Updated: 2025/12/29 21:05:26 by haatwata         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= ex03
CXX		= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98

SRCS		=	main.cpp \
			AMateria.cpp Ice.cpp Cure.cpp \
			Character.cpp MateriaSource.cpp

OBJS		= $(SRCS:%.cpp=%.o)

all: $(NAME)

$(NAME): $(OBJS) 
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re test
