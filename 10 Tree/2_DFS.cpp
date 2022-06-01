#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

class node
{
public:
    int val;
    node *left, *right;

    node(int _val)
    {
        val = _val;
        left = right = NULL;
    }
};

// Time ans Space Complexity of inorder, postorder and preorder is O(N) (If tree is Skewed Tree)

// left, root, right
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

// root, left, right
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// left , right, root
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->right = new node(5);
    root->left->left = new node(8);
    root->right->right = new node(6);
    root->right->left = new node(7);
    inorder(root); // 8 2 5 1 7 3 6
    cout << endl;
    preorder(root); // 1 2 8 5 3 7 6
    cout << endl;
    inorder(root); // 8 2 5 1 7 3 6
    cout << endl;

    /*
                      1
                  /     \
                2        3
             /    \    /  \
           8       5  7   6
   */

    return 0;
}