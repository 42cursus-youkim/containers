$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INC) $^ -o $@

.PHONY: all run clean re

all: $(TARGET)

run: all
	./$(TARGET)

clean:
	$(RM) test.out

re:
	$(MAKE) --no-print-directory clean
	$(MAKE) --no-print-directory all
