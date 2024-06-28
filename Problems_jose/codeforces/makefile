# Makefile for compiling a C++ program with customizable source files

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -o2

# Target executable
TARGET = myprogram

# Default source files (if not specified as arguments)
SRCS_DEFAULT = mfile_test.cpp

# If SOURCES is not defined, use SRCS_DEFAULT
SOURCES ?= $(SRCS_DEFAULT)

# Object files
OBJS = $(SOURCES:.cpp=.o)

# Default rule
all: $(TARGET)

# Rule to link the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

# Rule to compile .cpp files to .o files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)