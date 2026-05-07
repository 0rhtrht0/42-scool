NAME = computor

BONUS = computor_bonus

CXX = c++

CXXFLAGS = -Wall -Wextra -Werror

SRCS = computor_v1.cpp main.cpp
SRCS_BONUS = computor_v1_bonus.cpp main_bonus.cpp

OBJS = $(SRCS:.cpp=.o)

OBJS_BONUS = $(SRCS_BONUS:.cpp=.o)

%.o:%.cpp
		$(CXX) $(CXXFLAGS) -c $(SRCS)

all: $(NAME)

$(NAME): $(OBJS)
		$(CXX) $(CXXFLAGS) $(SRCS) -o $(NAME)

bonus: $(OBJS_BONUS)
		$(CXX) $(CXXFLAGS) $(SRCS_BONUS) -o $(BONUS)

clean:
		rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean	
		rm -f $(NAME) $(BONUS)

re: fclean all

.PHONY: re clean fclean all