NAME = computor_v2

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror 

SRCS = computor.cpp main.cpp utils.cpp function.cpp matrice.cpp const.cpp

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