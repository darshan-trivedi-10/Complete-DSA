// https://www.codingninjas.com/codestudio/problems/implement-trie_1387095
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{

    Node *links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool isContainKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void increseEnd()
    {
        cntEndWith++;
    }

    void increasePrefix()
    {
        cntPrefix++;
    }

    void deleteEnd()
    {
        cntEndWith--;
    }

    void reducePrefix()
    {
        cntPrefix--;
    }

    int getEnd()
    {
        return cntEndWith;
    }

    int getPrefix()
    {
        return cntPrefix;
    }
};

class Trie
{
private:
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }

    void insert(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                temp->put(word[i], new Node());
            }

            temp = temp->get(word[i]);
            temp->increasePrefix();
        }
        temp->increseEnd();
    }

    int countWordsEqualTo(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                return 0;
            }

            temp = temp->get(word[i]);
        }
        return temp->getEnd();
    }

    int countWordsStartingWith(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                return 0;
            }

            temp = temp->get(word[i]);
        }
        return temp->getPrefix();
    }

    void erase(string &word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                return;
            }
            temp = temp->get(word[i]);
            temp->reducePrefix();
        }

        temp->deleteEnd();
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}