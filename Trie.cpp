#include "Trie.h"
#include <iostream>
#include<stdio.h>

using namespace std;

Trie::Trie() {
  isWord = false;
  // Trie trieArray = new Trie*[26]();
  for (int i = 0; i < 26; i++) {
    trieArray[i] = nullptr;
  }
}

Trie::~Trie() {
  delete [] trieArray;
}

Trie::Trie(const Trie& other) {
  isWord = other.isWord;
  // Trie **trieArray = new Trie*[26]();
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
  if (word.length() == 0) {
    isWord = true;
    return;
  }
  else {
      int chInt = letterToInt(word[0]);
      if (this->trieArray[chInt] == nullptr) {
        Trie *tr = new Trie();
        this->trieArray[chInt] = tr;
      }

      this->trieArray[chInt]->addAWord(word.substr(1, word.length() - 1));
  }
}


bool Trie::isAWord(string word) {
  if (word.length() == 0)
    return false;
  else {
    int count = 0; // count of what letter we're on in the word
    int index; // index into alphabet array
    Trie *ptr = this;
    while (ptr != nullptr) {
      index = letterToInt(word[count]);
      if (ptr->isWord && ((unsigned int)count == word.length()))
        return true;
      ptr = ptr->trieArray[index];
      count++;
    }
    return false;

  }
}

vector<string> Trie::allWordsStartingWithPrefix(string prefix)
{
  vector<string> wordVector;
  int len = prefix.length();
  Trie *ptr = this;
  int index = 0;
  int count = 0;
  if (len == 0) {
    return returnAllFromNode(ptr, wordVector, "");
  } else {
    for (int i = 0; i < len; i++) {
      index = letterToInt(prefix[count]);
      ptr = ptr->trieArray[index];
      count++;
    }
    return returnAllFromNode(ptr, wordVector, prefix);
  }
}

int Trie::letterToInt(char letter) {
  return (int)letter - 97;
}

char Trie::intToLetter(int num) {
  return (char)(num + 97);
}

vector<string> Trie::returnAllFromNode(Trie *ptr, vector<string> &vec, string prefix){
  if (ptr != nullptr) {
    if (ptr->isWord) {
      vec.push_back(prefix);
    }

    for (int i = 0; i < 26; i++) {
      if (ptr != nullptr) {
        char nxt = intToLetter(i);
        returnAllFromNode(ptr->trieArray[i], vec, prefix + nxt);
      }

    }
  }
  return vec;
}
