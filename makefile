main.o: src/main.cpp src/headers/lexer.hpp
	g++ -Wall -c ./src/main.cpp -o main.o
lexer.o: src/lexer.cpp src/headers/lexer.hpp
	g++ -Wall -c ./src/lexer.cpp -o lexer.o
epsilon: main.o lexer.o
	mkdir build
	g++ -Wall -o ./build/epsilon main.o lexer.o
clean: build/epsilon
	rm -rf epsilon