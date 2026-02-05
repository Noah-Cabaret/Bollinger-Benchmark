TARGET = backtest_cpp

CXX = g++

CXXFLAGS = -std=c++17 -I include -O3

SRCS = main.cpp src/DataLoader.cpp src/Strategy.cpp src/Engine.cpp

OBJS = $(SRCS:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(TARGET)

clean:
	rm -f src/*.o *.o $(TARGET)

run: all
	./$(TARGET)