#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *newNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->right = newNode->left = nullptr;
    return newNode;
}

int depth(Node *node)
{
    int d = 0;
    while (node != nullptr)
    {
        d++;
        node = node->left;
    }
    return d;
}

bool isPerfectR(Node *root, int d, int level = 0)
{
    // Ako nema korijena
    if (root == nullptr)
        return true;

    // Ako korijen nema djece
    if (root->left == nullptr && root->right == nullptr)
        return (d == level + 1);

    // Ako nema ili lijevo ili desno dijete
    if (root->left == nullptr || root->right == nullptr)
        return false;

    return (isPerfectR(root->left, d, level + 1) &&
            isPerfectR(root->right, d, level + 1));
}

bool isPerfect(Node *root)
{
    int d = depth(root);
    return isPerfectR(root, d);
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    if (isPerfect(root))
        cout << "Drvo je savrseno binarno stablo \n";
    else
        cout << "Drvo nije savrseno binarno stablo \n";
}