CXXFLAGS = -Iinclude -std=c++23 -Wall -save-temps
LDFLAGS = -L deps/libs

all: epsilon
epsilon: src/main.cpp src/compile.cpp src/lexer.cpp src/run.cpp src/flagHandler.cpp
	$(CXX) $(CXXFLAGS) src/*.cpp -c
	$(CXX) *.o -o build/epsilon
	mv *.o build/
	mv *.ii build/
	mv *.bc build/
	mv *.s build/
clean:
	rm -rf build/*
	rm -rf *.o
	