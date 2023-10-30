CC = g++
CFLAGS = -Wall -g
SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXECUTABLE = main

all:
	gcc main.o main.cpp -o main
	gcc readfile.o readfile.cpp -o readfile
	gcc wordfinder.o wordfinder.cpp -o wordfinder
	gcc fileprocessor.o fileprocessor.cpp -o fileprocessor

readfile.o: file.h
	gcc -c readfile.cpp

clean:
	ifeq ($(OS),Windows_NT)
        rmdir /s /q build
    else
        rm -rf build/
    endif
