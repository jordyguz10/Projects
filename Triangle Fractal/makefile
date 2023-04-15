CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++17
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: TFractal
TFractal: Triangle.o TFractal.o 
	$(CC) $(CFLAGS) -o TFractal Triangle.o TFractal.o $(SFML)
TFractal.o: Triangle.h TFractal.cpp
	$(CC) $(CFLAGS) -c TFractal.cpp
Triangle.o: Triangle.h Triangle.cpp
	$(CC) $(CFLAGS) -c Triangle.cpp
clean:
	rm *.o TFractal