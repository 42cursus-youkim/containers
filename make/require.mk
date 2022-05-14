INC = $(addprefix -I src/, containers/ utils/ )
INC += $(addprefix -I test/, test/ util/ )

SRC = $(wildcard test/*.cpp) test/main.cpp
