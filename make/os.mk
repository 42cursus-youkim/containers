OS:=$(shell uname -s)

ifeq ($(OS),Linux)
  ICON := 🐧
  CXX := clang++
else ifeq ($(OS),Darwin)
  ICON := 🍏
  CXX := c++
else
  $(error sorry, $(OS) not supported)
endif
