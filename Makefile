# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asebrech <asebrech@student.42nice.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/17 14:07:04 by asebrech          #+#    #+#              #
#    Updated: 2022/06/29 12:03:36 by asebrech         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX = clang++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -D STD=1
CXXFLAGS2 = -Wall -Wextra -Werror -std=c++98 -D STD=0
NAME = std 
SRC =	main.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@ 
	$(CXX) $(CXXFLAGS2) -c main.cpp -o main_ft.o
	$(CXX) $(CXXFLAGS2) main_ft.o -o ft 

%.o : %.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJ)
	@rm -rf main_ft.o

fclean : clean
	@rm -rf $(NAME)
	@rm -rf ft

re : fclean all

.PHONY : all clean fclean re
