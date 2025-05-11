CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11
SRC = SquareMat.cpp
HDR = SquareMat.hpp
TEST = test.cpp
MAIN = Main.cpp
DOCTEST = doctest.h

all: Main

Main: $(MAIN) $(SRC) $(HDR)
	$(CXX) $(CXXFLAGS) -o Main $(MAIN) $(SRC)

test: $(TEST) $(SRC) $(HDR) $(DOCTEST)
	$(CXX) $(CXXFLAGS) -o test_exec $(TEST) $(SRC)
	./test_exec

valgrind: test
	valgrind --leak-check=full ./test_exec

clean:
	rm -f Main test_exec *.o
