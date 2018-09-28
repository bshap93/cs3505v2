#include <sstream>
#include <fstream>
#include <iostream>
#include "Trie.h"
using namespace std;

int main(int argc, const char** argv) {
  if (argc != 3) {
    cout<<"2 arguments were expected";
    return 1;
  }
  Trie *testTrie = new Trie();
  string wordLine;
  ifstream wordFile (argv[0]);
  if (wordFile) {
    while(getline(wordFile, wordLine)) {
      testTrie->addAWord(wordLine);
    }
  }
  else {
    cout << "A problem opening the file occured.\ns";
    cout << "Make sure the file exists at the location";
    cout << "you specified\n";
    return 1;
  }


  string queryLine;
  ifstream queryFile (argv[0]);
  if (queryFile) {
    while(getline(queryFile, queryLine)) {
      if (testTrie->isAWord(queryLine) == true) {
        cout << queryLine << "is found\n";
      }
      else {
        cout << queryLine << "is not found, did you mean:\n";
        auto vec = testTrie->allWordsStartingWithPrefix(queryLine);
        for(int i=0; (unsigned int)i < vec.size(); i++)
          cout << "\t\t"<< vec[i] << endl;
      }
    }
  }
  else {
    cout << "A problem opening the file occured.\ns";
    cout << "Make sure the file exists at the location";
    cout << "you specified\n";
    return 1;
  }

  return 0;
}
