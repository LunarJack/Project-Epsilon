CXXFLAGS = -Isrc/include -Ldeps/libs
all: makebuild epsilon installer
makebuild:
	mkdir build
epsilon: src/main.cpp src/compile.cpp src/lexer.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -c
	$(CXX) $(CXXFLAGS) src/compile.cpp -c
	$(CXX) $(CXXFLAGS) src/lexer.cpp -c
	$(CXX) main.o compile.o lexer.o -o build/epsilon
	rm -rf *.o
installer: src/installer.cpp
	$(CXX) $(CXXFLAGS) src/installer.cpp -c
	$(CXX) -Ldeps/libs  installer.o -o build/installer
clean:
	rm -rf build