OS:=$(shell uname -s)

# get number of process
ifeq ($(OS),Linux)
  NPROC := $(shell nproc)
else ifeq ($(OS),Darwin)
  NPROC := $(shell grep ^processor /proc/cpuinfo | wc -l')
else # Fallback to 1 core
  NPROC := 1
endif

JOB := -j $(NPROCS)
