.PHONY: test

TARGET := test/build/test.out

$(TARGET):
	cmake -C test/
	ninja -C test/build/

ninja: $(TARGET)

test: ninja
	$(TARGET)
