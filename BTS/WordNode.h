#ifndef WORDNODE_H
#define WORDNODE_H
#include <vector>
#include <string>

using namespace std;


class WordNode
{
    public:
        WordNode();
        string m_word;
        int m_wordCount = 0;
        int m_uniqueWords;
        vector<int> m_lineNumbers;

        int wordCount;
        WordNode * m_left;
        WordNode * m_right;
        WordNode * m_parent;

    protected:

    private:
};

#endif // WORDNODE_H
