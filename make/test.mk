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

leak: all
	colour-valgrind ./$(TARGET)

test-vec:
	cd containers_test/ \
	&& ./do.sh vector
