#include "Trie.h"

int main(int argc, const char** argv) {
  Trie *t = new Trie();
  auto a = t->letterToInt('c');
  auto b = t->intToLetter(26);
  t->addAWord("cat");
  return 0;
}
