TARGET = main
CXX = g++
FLAGS = -std=c++17 -Wall -Wextra -Wpedantic -D_GNU_SOURCE -Werror=all -O2
SRCS = main.cpp SentimentDictionary.cpp ResultAnalysis.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = SentimentDictionary.hpp ResultAnalysis.hpp

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(FLAGS) -o $(TARGET) $(OBJS)

%.o: %.cpp $(DEPS)
	$(CXX) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)

distclean: clean
	rm -f *~

.PHONY: all clean distclean
