# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = 

# Target executable
TARGET = taskforge

# Source files
SRCS = ActiveTripIterator.cpp \
       CompletedState.cpp \
       CompleteHierarchyIterator.cpp \
       DriverAssignedState.cpp \
       InTransitState.cpp \
       OperationIterator.cpp \
       PriorityTripFeature.cpp \
       Region.cpp \
       RequestedState.cpp \
       Trip.cpp \
       TripFeature.cpp \
       TripState.cpp \
       UberBlackFeature.cpp \
       UberOperation.cpp \
       main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Header files
HEADERS = ActiveTripIterator.h \
          CompletedState.h \
          CompleteHierarchyIterator.h \
          DriverAssignedState.h \
          InTransitState.h \
          OperationIterator.h \
          PriorityTripFeature.h \
          Region.h \
          RequestedState.h \
          Trip.h \
          TripFeature.h \
          TripState.h \
          UberBlackFeature.h \
          UberOperation.h

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

# Compile source files to object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run the program
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(OBJS) $(TARGET)

# Clean and rebuild
rebuild: clean all

# Debug build with more flags
debug: CXXFLAGS += -DDEBUG -O0
debug: clean all

# Phony targets (not actual files)
.PHONY: all run clean rebuild debug
