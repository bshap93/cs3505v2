CC = g++
CFLAGS = -std=c++11 -Wall -fsanitize=address -fsanitize=undefined

TrieTest: TrieTest.o Trie.o
	$(CC) $(CFLAGS) -o TrieTest TrieTest.o Trie.o 

TrieTest.o: TrieTest.cpp
	$(CC) $(CFLAGS) -c TrieTest.cpp

Trie.o: Trie.cpp Trie.h
	$(CC) $(CFLAGS) -c Trie.cpp

clean:
	rm -f *.o spiralPDF
