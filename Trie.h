
#ifndef TRIE_H
#define TRIE_H
#include <string>
#include <vector>

class Trie {
public:
  Trie();
  ~Trie();
  Trie(const Trie& other);
  Trie& operator=(const Trie& other);
  void addAWord(std::string word);
  bool isAWord(std::string word);
  std::vector<std::string> allWordsStartingWithPrefix(std::string prefix);
  int letterToInt(char letter);
  char intToLetter(int num);
private:
  Trie* addAWordHelper(std::string word);
  bool isWord;
  Trie* trieArray[26];
};

#endif
