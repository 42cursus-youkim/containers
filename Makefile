TARGET := test.out

include make/os.mk
include make/require.mk

CXXFLAGS = \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow -Wpedantic \

CXXFLAGS += -g3 #-fsanitize=address -fno-omit-frame-pointer

include make/test.mk

