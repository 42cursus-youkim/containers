OS:=$(shell uname -s)

ifeq ($(OS),Linux)
  ICON := 🐧
  NPROC := $(shell nproc)
  CXX := clang++
else ifeq ($(OS),Darwin)
  ICON := 🍏
  NPROC := $(shell grep ^processor /proc/cpuinfo | wc -l')
  CXX := c++
else
  $(error sorry, $(OS) not supported)
endif
