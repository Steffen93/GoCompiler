# Makefile

FILES	= Lexer.c Parser.c Expression.c main.cpp
CC	= g++
CFLAGS	= -g -ansi

test:		$(FILES)
		$(CC) $(CFLAGS) $(FILES) -o main

Lexer.c:	Lexer.l 
		flex Lexer.l

Parser.c:	Parser.y Lexer.c
		bison Parser.y

clean:
		rm -f *.o *~ Lexer.c Lexer.h Parser.c Parser.h main
