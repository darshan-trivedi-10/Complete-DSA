// https://www.codingninjas.com/codestudio/problems/complete-string_2687860
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

    bool isPrefixExits(string word)
    {
        bool flag = true;
        Node *temp = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (temp->isContainKey(word[i]))
            {
                temp = temp->get(word[i]);
                flag = flag & temp->isEnd();
            }
            else
            {
                flag = false;
            }
        }

        return flag;
    }
};

string completeString(int n, vector<string> &a)
{
    Trie t;
    for (int i = 0; i < n; i++)
    {
        t.insert(a[i]);
    }

    string ans = "";

    for (int i = 0; i < n; i++)
    {
        if (t.isPrefixExits(a[i]))
        {
            if (a[i].size() > ans.size())
            {
                ans = a[i];
            }
            else if (a[i].size() == ans.size() and a[i] < ans)
            {
                ans = a[i];
            }
        }
    }

    if (ans == "")
    {
        ans = "None";
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}