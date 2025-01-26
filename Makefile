CXX = g++
CXXFLAGS = -pedantic -Wall -Wextra -Wcast-align -Wcast-qual -Wctor-dtor-privacy -Wdisabled-optimization -Wformat=2 -Winit-self -Wmissing-declarations -Wmissing-include-dirs -Wold-style-cast -Woverloaded-virtual -Wredundant-decls -Wshadow -Wsign-conversion -Wsign-promo -Wstrict-overflow=5 -Wswitch-default -Wundef -Wno-unused -g
INCLUDE := src/include
LIBS := deps/libs
BUILD := build

all: build installer epsilon epsilonc
build:
	mkdir build
installer: src/installer.cpp
	$(CXX) -I$(INCLUDE) -L$(LIBS) -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit $(CXXFLAGS) src/installer.cpp -o build/installer
epsilon: src/main.cpp
	$(CXX) -I$(INCLUDE) -L$(LIBS) $(CXXFLAGS) src/main.cpp -o build/epsilon
epsilonc: compile.o
	$(CXX) -I$(INCLUDE) -L$(LIBS) $(CXXFLAGS) compile.o -o build/epsilonc
	rm -rf compile.o
compile.o: src/compile.cpp src/lexer.cpp src/parser.cpp
	$(CXX) -I$(INCLUDE) -L$(LIBS) $(CXXFLAGS) -c src/compile.cpp
clean:
	rm -rf build
	rm -rf *.o