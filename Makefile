CXXFLAGS = -Isrc/include -std=c++20
LDFLAGS = -L deps/libs

all: makebuild epsilon
makebuild:
	mkdir build
epsilon: src/main.cpp src/compile.cpp src/lexer.cpp src/run.cpp src/flagHandler.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -c
	$(CXX) $(CXXFLAGS) src/compile.cpp -c
	$(CXX) $(CXXFLAGS) src/lexer.cpp -c
	$(CXX) $(CXXFLAGS) src/run.cpp -c
	$(CXX) $(CXXFLAGS) src/flagHandler.cpp -c
	$(CXX) main.o compile.o lexer.o run.o flagHandler.o -o build/epsilon
clean:
	rm -rf build
	rm -rf *.o