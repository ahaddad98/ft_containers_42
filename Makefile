# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amine <amine@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/20 16:13:12 by ahaddad           #+#    #+#              #
#    Updated: 2021/10/22 13:43:15 by amine            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_container

# FLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = main.cpp \
			
HDRS = Vector/Vector.hpp \
		Stack/Stack.hpp \
		Map/Map.hpp \
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
