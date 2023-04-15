CC = g++
CFLAGS = -Wall -Werror -pedantic -std=c++17
SFML = -lsfml-graphics -lsfml-window -lsfml-system

all: PhotoMagic
PhotoMagic: PhotoMagic.o FibLFSR.o
	$(CC) $(CFLAGS) -o PhotoMagic PhotoMagic.o FibLFSR.o $(SFML)
PhotoMagic.o: FibLFSR.h PhotoMagic.cpp
	$(CC) $(CFLAGS) -c PhotoMagic.cpp 
FibLFSR.o: FibLFSR.h FibLFSR.cpp
	$(CC) $(CFLAGS) -c FibLFSR.cpp 
clean:
	rm *.o PhotoMagic