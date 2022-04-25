CXX := c++
CXXFLAGS := -Wall -Wextra -Werror -std=c++98 -pedantic

SRC := $(wildcard *.cpp)
OBJ := $(SRC:.cpp=.o)

.c.a:
	$(CXX) $(CXXFLAGS) -c $< -o
	$(AR)
