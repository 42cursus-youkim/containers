TARGET := test.out
include make/parallel.mk

INC_PREFIX := -I include/
INC := $(addprefix $(INC_PREFIX), containers iterator utils)

CXX := c++
CXXFLAGS := \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow \

$(TARGET):
	$(CXX) $(CXXFLAGS) $(INC) test/main.cpp -o test.out

all: $(TARGET)

clean:
	$(RM) test.out

re:
	$(MAKE) --no-print-directory clean
	$(MAKE) --no-print-directory all
