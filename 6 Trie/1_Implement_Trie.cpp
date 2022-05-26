// https://leetcode.com/problems/implement-trie-prefix-tree/
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

struct Node
{

    Node *links[26];
    bool flag = false;

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

    void setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
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

    void insert(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                temp->put(word[i], new Node());
            }

            temp = temp->get(word[i]);
        }

        temp->setEnd();
    }

    bool search(string word)
    {
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]) == false)
            {
                return false;
            }
            temp = temp->get(word[i]);
        }

        return temp->isEnd();
    }

    bool startsWith(string prefix)
    {
        Node *temp = root;
        for (int i = 0; i < prefix.size(); i++)
        {
            if (temp->isContainKey(prefix[i]) == false)
            {
                return false;
            }
            temp = temp->get(prefix[i]);
        }

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}