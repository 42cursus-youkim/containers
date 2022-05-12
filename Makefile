TARGET := test.out

include make/os.mk
include make/parallel.mk

INC := $(addprefix -I src/, containers/ utils/)

CXXFLAGS = \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow \

include make/test.mk

