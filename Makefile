DIR_TO_CHECK_FOR = /opt/homebrew
DIR_TO_CHECK_FOR2 = /opt/local
ifeq ($(OS),Windows_NT)
    PLATFORM = "WIN32"
else
    UNAME_S := $(shell uname -s)
    ifeq ($(UNAME_S),Linux)
        PLATFORM = "LINUX"
    endif
    ifeq ($(UNAME_S),Darwin)
        PLATFORM = "OSX"
    endif
endif
CXXFLAGS = -Isrc/include -std=c++20
LDFLAGS = -L deps/libs
all: makebuild epsilon installer
makebuild:
	mkdir build
epsilon: src/main.cpp src/compile.cpp src/lexer.cpp
	$(CXX) $(CXXFLAGS) src/main.cpp -c
	$(CXX) $(CXXFLAGS) src/compile.cpp -c
	$(CXX) $(CXXFLAGS) src/lexer.cpp -c
	$(CXX) main.o compile.o lexer.o -o build/epsilon
	rm -rf *.o
installer:

clean:
	rm -rf build
	rm -rf *.o