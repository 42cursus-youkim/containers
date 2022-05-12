ifneq ($(PARALLEL), 0)
  CXXFLAGS += -j $(NPROCS)
endif
