// https://www.codingninjas.com/codestudio/problems/childrensumproperty_790723
#include <bits/stdc++.h>
using namespace std;
using lli = long long int;
using ll = long long;
#define endl '\n'

template <class T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

    BinaryTreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }

    int child = 0;
    if (root->left)
    {
        child += root->left->data;
    }

    if (root->right)
    {
        child += root->right->data;
    }

    if (child >= root->data)
    {
        root->data = child;
    }
    else
    {
        if (root->left)
        {
            root->left->data = root->data;
        }
        if (root->right)
        {
            root->right->data = root->data;
        }
    }

    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
    {
        tot += root->left->data;
    }
    if (root->right)
    {
        tot += root->right->data;
    }

    if (root->left or root->right)
    {
        root->data = tot;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    return 0;
}