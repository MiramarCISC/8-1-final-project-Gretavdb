CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -pedantic -Iinclude

APP_TARGET = main
TEST_TARGET = test_project

APP_SOURCES = src/main.cpp src/project.cpp
TEST_SOURCES = tests/test_project.cpp src/project.cpp

.PHONY: all test clean run

all: $(APP_TARGET)

$(APP_TARGET): $(APP_SOURCES)
	$(CXX) $(CXXFLAGS) $(APP_SOURCES) -o $(APP_TARGET)

$(TEST_TARGET): $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) $(TEST_SOURCES) -o $(TEST_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

run: $(APP_TARGET)
	./$(APP_TARGET)

clean:
	rm -f $(APP_TARGET) $(TEST_TARGET) inventory_report.txt tests/resources/test_inventory_input.txt tests/resources/test_inventory_report_output.txt
