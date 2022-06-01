#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class Node
{
public:
    int val;
    Node *left, *right;

    Node(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    Node *root = new Node(1);
    /*
                1
  */
    root->left = new Node(2);
    /*
                   1
                /
            2
   */
    root->right = new Node(3);
    /*
                 1
              /   \
            2      3
    */
    root->left->right = new Node(5);
    /*
                  1
               /   \
             2      3
              \
                5
  */

    return 0;
}