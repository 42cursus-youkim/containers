TARGET := test.out
include make/parallel.mk

INC := $(addprefix -I src/, containers utils)

CXX := c++
CXXFLAGS := \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow \

$(TARGET):
	$(CXX) $(CXXFLAGS) $(INC) test/main.cpp -o test.out

run: $(TARGET)
	./$(TARGET)

all: $(TARGET)

clean:
	$(RM) test.out

re:
	$(MAKE) --no-print-directory clean
	$(MAKE) --no-print-directory all
