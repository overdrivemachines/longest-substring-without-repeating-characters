
# Variables to control Makefile operation

CC = g++
CFLAGS = -Wall -g

longest-substring-without-repeating-characters: longest-substring-without-repeating-characters.o
	$(CC) $(CFLAGS) -o longest-substring-without-repeating-characters longest-substring-without-repeating-characters.o

longest-substring-without-repeating-characters.o: longest-substring-without-repeating-characters.cpp
	$(CC) $(CFLAGS) -c longest-substring-without-repeating-characters.cpp

clean:
	rm -rf longest-substring-without-repeating-characters longest-substring-without-repeating-characters.o
