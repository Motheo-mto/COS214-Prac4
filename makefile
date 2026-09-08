CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g
LDFLAGS = 

TARGET = taskforge

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

OBJS = $(SRCS:.cpp=.o)

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

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	rm -f $(OBJS) $(TARGET)

rebuild: clean all

debug: CXXFLAGS += -DDEBUG -O0
debug: clean all

.PHONY: all run clean rebuild debug
