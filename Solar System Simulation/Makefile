CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++17
SFML = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

all: NBody
NBody: CelestialBody.o Universe.o main.o
	$(CC) $(CFLAGS) -o NBody main.o CelestialBody.o Universe.o $(SFML)
main.o: Universe.h CelestialBody.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp
Universe.o: Universe.h Universe.cpp
	$(CC) $(CFLAGS) -c Universe.cpp
CelestialBody.o: CelestialBody.h CelestialBody.cpp
	$(CC) $(CFLAGS) -c CelestialBody.cpp
clean:
	rm *.o NBody