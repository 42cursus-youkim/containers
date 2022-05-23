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
