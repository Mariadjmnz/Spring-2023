#include <iostream>
#include <bits/stdc++.h>
#include "WordTree.h"
#include "WordNode.h"

using namespace std;

int main()
{
    int lineNumber = 1;
    fstream file;
    string line, word, filename;
    filename = "Test.txt";
    file.open(filename.c_str());

    WordTree * tree = new WordTree;

    //while (file >> word) {
      while (getline(file,line)) {
        istringstream iss(line);
        while (iss >> word) {
           word.erase(remove(word.begin(), word.end(), ','), word.end());
           word.erase(remove(word.begin(), word.end(), '.'), word.end());
           word.erase(remove(word.begin(), word.end(), ';'), word.end());
           word.erase(remove(word.begin(), word.end(), '-'), word.end());
           transform (word.begin(), word.end(), word.begin(), ::tolower);
           tree->insert(word,lineNumber);
        }
        lineNumber++;
    }

    tree->printTreeInOrder();

    cout << "There are " << tree->countWords() << " in the file" << endl;
    cout << "There are " << tree->countUniqueWords() << " unique words in the file" << endl;
    cout << "Alphabetical first word: " << tree->firstWord() << endl;
    cout << "Alphabetical last word: " << tree->lastWord() << endl;

    return 0;
}
