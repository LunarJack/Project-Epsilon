CXXFLAGS = -Iinclude -std=c++20 -Wall
LDFLAGS = -L deps/libs

all: makebuild epsilon
makebuild:
	mkdir bin
epsilon: src/main.cpp src/compile.cpp src/lexer.cpp src/run.cpp src/flagHandler.cpp
	$(CXX) $(CXXFLAGS) src/*.cpp -c
	$(CXX) *.o -o bin/epsilon
clean:
	rm -rf bin
	rm -rf *.o
clear:
	clear
fullclean: clean clear
	