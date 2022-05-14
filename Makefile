TARGET := test.out

include make/os.mk
include make/parallel.mk
include make/require.mk

CXXFLAGS = \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow -Wpedantic \

include make/test.mk

