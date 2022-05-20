INC = -I containers/

INC += $(addprefix -I test/, test/ util/ )

SRC = $(wildcard test/*.cpp) test/main.cpp
OBJ := $(SRC:%.cpp=%.o)
DEP := $(OBJ:%.o=%.d)

# CXXFLAGS += -MMD
