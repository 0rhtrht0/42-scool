NAME = computor

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = computor_v1.cpp main.cpp

OBJS = $(SRCS:.cpp=.o)

%.o:%.cpp
		$(CXX) $(CXXFLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

clean:
		rm -f $(OBJS)

fclean: clean	
		rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all