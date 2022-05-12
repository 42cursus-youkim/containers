TARGET := test.out

include make/os.mk
include make/parallel.mk
include make/include.mk

CXXFLAGS = \
	-Wall -Wextra -Werror -std=c++98 \
	-Wpedantic -Wconversion -Wshadow \

include make/test.mk

