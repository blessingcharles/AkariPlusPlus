CC=g++
CFLAGS=-g -Wall -std=c++17

all: AkariPlusPlus

AppRepl.o: AppRepl.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
Lexer.o: Lexer.cpp
	$(CC) $(CFLAGS) -c -o $@ $^
SyntaxToken.o: SyntaxToken.cpp
	$(CC) $(CFLAGS) -c -o $@ $^

AkariPlusPlus: AkariPlusPlus.cpp AppRepl.o Lexer.o SyntaxToken.o
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o