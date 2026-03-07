
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra
TARGET = imagestacker
SOURCES = main.cpp stacker.cpp pixel.cpp
OBJECTS = $(SOURCES:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJECTS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)