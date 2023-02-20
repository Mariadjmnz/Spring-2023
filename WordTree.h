#ifndef WORDTREE_H
#define WORDTREE_H

#include "WordNode.h"
#include <string>
#include <vector>
#include <iostream>


class WordTree
{
    public:
        WordTree();
        void insert(string word, int line);
        void printTreeInOrder();
        int countUniqueWords();
        int countWords();
        string firstWord();
        string lastWord();
        void remove(string);
        vector<int> wordLines(string word);

    protected:
        WordNode * insert(WordNode * node, string word, int lineNumbers);
        void printTreeInOrder(WordNode * node);
        int countUniqueWords (WordNode * node);
        int countWords(WordNode * node);
        string firstWord(WordNode * node);
        string lastWord(WordNode * node);
        WordNode * remove(WordNode * node, string word);
        vector<int> wordLines (WordNode * node, string word);

    private:
        WordNode * m_root;
};

#endif // WORDTREE_H
