CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -I./headers
LDFLAGS = 

SRC_DIR = src
HEADER_DIR = headers
BUILD_DIR = build
BIN_DIR = .

TARGET = $(BIN_DIR)/pet_shelter

SOURCES = $(SRC_DIR)/main.cpp \
          $(SRC_DIR)/pet.cpp \
          $(SRC_DIR)/employee.cpp \
          $(SRC_DIR)/shelter.cpp

OBJECTS = $(BUILD_DIR)/main.o \
          $(BUILD_DIR)/pet.o \
          $(BUILD_DIR)/employee.o \
          $(BUILD_DIR)/shelter.o

HEADERS = $(HEADER_DIR)/entity.hpp \
          $(HEADER_DIR)/pet.hpp \
          $(HEADER_DIR)/employee.hpp \
          $(HEADER_DIR)/shelter.hpp \
          $(HEADER_DIR)/task.hpp

all: $(TARGET)

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)
	@echo "Build complete: $(TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	@./$(TARGET)

run_task: $(TARGET)
	@./$(TARGET) 0 FEED 5

clean:
	@rm -rf $(BUILD_DIR)
	@rm -f $(TARGET)
	@echo "Cleaned build files"

rebuild: clean all

rebuild_headers: clean all

print_vars:
	@echo "CXX: $(CXX)"
	@echo "CXXFLAGS: $(CXXFLAGS)"
	@echo "SOURCES: $(SOURCES)"
	@echo "OBJECTS: $(OBJECTS)"
	@echo "TARGET: $(TARGET)"

.PHONY: all run run_task clean rebuild rebuild_headers print_vars