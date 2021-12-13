# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaddad <ahaddad@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 16:13:12 by ahaddad           #+#    #+#              #
#    Updated: 2021/12/13 19:53:28 by ahaddad          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container

FLAGS = -std=c++98

SRCS = main.cpp \
			
HDRS = Vector/Vector.hpp \
		Stack/Stack.hpp \
		Map/map_iterator.hpp \
		Map/Map.hpp \
		Map/pair.hpp \
		Vector/iterator.hpp \
		Vector/iterator_traits.hpp \
		

OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@clang++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\033[1;33m"
	@echo "			The binary file has been created!\n"
	@echo "\033[0m"

%.o: %.cpp $(HDRS)
	@echo "\033[0;33m"
	clang++ $(FLAGS) -c $< -o $@
	@echo "\033[0m"

clean:
	@rm -rf $(OBJS)
	@echo "\033[0;31m"
	@echo "			The objects files has been removed!\n"
	@echo "\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;31m"
	@echo "			The binary file has been removed!\n"
	@echo "\033[0m"

re: fclean all