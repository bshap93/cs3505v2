#include "Trie.h"
#include <iostream>
#include<stdio.h>

using namespace std;

Trie::Trie() {
  isWord = false;
  Trie **trieArray = new Trie*[26]();
  for (int i = 0; i < 26; i++) {
    trieArray[i] = nullptr;
  }
}

Trie::~Trie() {
  delete [] trieArray;
}

Trie::Trie(const Trie& other) {
  isWord = other.isWord;
  Trie **trieArray = new Trie*[26]();
  for (int i = 0; i < 26; i++) {
    trieArray[i] = other.trieArray[i];
  }
}

Trie& Trie::operator=(const Trie& other) {
  if (this != &other) {
    isWord = other.isWord;
    Trie **trieArray = new Trie*[26]();
    for (int i = 0; i < 26; i++) {
      trieArray[i] = other.trieArray[i];
    }
    delete [] &other;
  }
  return *this;

}
void Trie::addAWord(string word) {
  if (word.length() < 1)
    cout << "word length cannot be < 1" << endl;
  else {
    addAWordHelper(word);
  }
}

Trie* Trie::addAWordHelper(string word) {
  if (word.length() == 1) {
    int chInt = letterToInt(word[0]);
    Trie *tr = new Trie();
    this->trieArray[chInt] = tr;
    this->isWord = true;
    return this;
  } else {
    int len = word.length() - 1;
    int chInt = letterToInt(word[len]);
    Trie *tr = new Trie();
    this->trieArray[chInt] = addAWordHelper(word.substr(0,word.length() - 1));
    return this;
  }
  // TODO: trie array is being altered by characters it's not
  // using
}


bool Trie::isAWord(string word) {

}

vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{

}

int Trie::letterToInt(char letter) {
  return (int)letter - 97;
}

char Trie::intToLetter(int num) {
  return (char)(num + 97);
}
