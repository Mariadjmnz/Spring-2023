#include "WordTree.h"
#include "WordNode.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

WordTree::WordTree() : m_root(NULL)
{
}

WordNode * WordTree::insert(WordNode * node, string word, int line)
{
    // If BST doesn't exist create a new node as root
    // or it's reached when there's no any child node
    // so we can insert a new node here
    if (node == NULL)
    {
        node = new WordNode;
        node->m_word = word;
        // set word count to one
        node->m_wordCount = 1;

        // initialize wordLines as a vector containing one element
        vector<int> wordLines = {line};

        // assign wordLines to node's m_lineNumbers member
        node->m_lineNumbers = wordLines;

        node->m_left = NULL;
        node->m_right = NULL;
        node->m_parent = NULL;
    }
    else if (node->m_word == word)
    {
        // Check if already in tree, if so increment word
        // count and add line number to vector
        node->m_wordCount++;
    }
     // If the given key is greater than node's key then go to right subtree
    else if (node->m_word < word)
    {
        node->m_right = insert(node->m_right, word, line);
        node->m_right->m_parent = node;
    }
    else if (node->m_word == word)
    {
        // Check if already in tree, if so increment word
        // count and add line number to vector
        node->m_wordCount++;
        node->m_lineNumbers.push_back(line);
    }

    // If the given key is smaller than node's key then go to left subtree
    else
    {
        node->m_left = insert(node->m_left,word,line);
        node->m_left->m_parent = node;
    }

    return node;
}

void WordTree::insert(string word, int line)
{
    // Invoking Insert() function and passing root node and given key
    m_root = insert(m_root, word,line);
}

void WordTree::printTreeInOrder(WordNode * node)
{
    // Stop printing if no node found
    if (node == NULL)
        return;

    // Get the smallest key first which is in the left subtree
    printTreeInOrder(node->m_left);

    // Print the key, word count, and line numbers
    cout << node->m_word << " occurs " << node->m_wordCount << " times, on line(s) ";

     // for loop to print out the vector
    for (int i=0; i < node->m_lineNumbers.size(); i++)
    {
        if (node->m_wordCount)
            cout << node->m_lineNumbers[i] << " \n";
    }

    // Continue to the greatest key which is in the right subtree
    printTreeInOrder(node->m_right);
}

void WordTree::printTreeInOrder()
{
    printTreeInOrder(m_root);
    cout << endl;
}

string WordTree::firstWord(WordNode * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->m_left == NULL)
    {
        return node->m_word;
    }
    else
    {
        return firstWord(node->m_left);
    }
}

string WordTree::firstWord()
{
    return firstWord(m_root);
}

string WordTree::lastWord(WordNode * node)
{
    if (node == NULL)
    {
        return NULL;
    }
    else if (node->m_right == NULL)
    {
        return node->m_word;
    }
    else
    {
        return lastWord(node->m_right);
    }
}

string WordTree::lastWord()
{
    return lastWord(m_root);
}

int WordTree::countUniqueWords()
{
    return countUniqueWords(m_root);
}

int WordTree::countUniqueWords(WordNode * node)
{
    if (node == NULL)
        return 0;

    return 1 + countUniqueWords(node->m_left) + countUniqueWords(node->m_right);
}

int WordTree::countWords()
{
    return countWords(m_root);
}

int WordTree::countWords(WordNode * node)
{
   if (node == NULL)
        return 0;

    ifstream file("test.txt");
    int countt = 0;
    string word;

    while (file >> word)
    {
        ++countt;
    }

    return countt;



}

