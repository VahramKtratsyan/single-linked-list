BUILD_DIR = build
SOURCE_DIR = src
TEST_DIR = test
TEMPLATE_DIR = template
INCLUDED_DIR = -I$(TEMPLATE_DIR)
CXX = clang++
CXXFLAGS = -Wunreachable-code -Wunreachable-code-loop-increment -Wunreachable-code-return \
-g -Wall -Wpedantic -Wextra -Werror -std=c++20
TEST_LIBS = -lgtest -lgtest_main -lpthread

all: $(BUILD_DIR)/test

$(BUILD_DIR)/test: $(BUILD_DIR)/test.o
	$(CXX) $(BUILD_DIR)/test.o -o $(BUILD_DIR)/test $(TEST_LIBS)

$(BUILD_DIR)/test.o: $(SOURCE_DIR)/$(TEST_DIR)/test.cpp $(TEMPLATE_DIR)/LinkedList.tpp $(TEMPLATE_DIR)/ListBuffer.tpp
	$(CXX) -c $(CXXFLAGS) $(INCLUDED_DIR) $(SOURCE_DIR)/$(TEST_DIR)/test.cpp -o $(BUILD_DIR)/test.o  

test:
	./$(BUILD_DIR)/test

clean:
	rm -f $(BUILD_DIR)/*

.PHONY: all test clean