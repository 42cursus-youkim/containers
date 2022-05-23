# -include $(DEP)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(INC) -c $< -o $@

$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(INC) -o $@ $^

.PHONY: all run clean re

all: $(TARGET)

run: all
	./$(TARGET)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) test.out

re:
	$(MAKE) --no-print-directory clean
	$(MAKE) --no-print-directory all

leak: all
	colour-valgrind --show-leak-kinds=all --leak-check=full ./$(TARGET)

test-vec:
	cd containers_test/ \
	&& ./do.sh vector

asan:
	./$(TARGET)
