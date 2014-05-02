# Makefile

FILES	= src/Lexer.c src/Parser.c src/Expression.c main.cpp
CC	= g++
CFLAGS	= -g -ansi

test:		$(FILES)
		$(CC) $(CFLAGS) $(FILES) -o main

Lexer.c:	Lexer.l 
		flex Lexer.l

Parser.c:	Parser.y Lexer.c
		bison Parser.y

clean:
		rm -f *.o *~ src/Lexer.c include/Lexer.h src/Parser.c include/Parser.h main.o
