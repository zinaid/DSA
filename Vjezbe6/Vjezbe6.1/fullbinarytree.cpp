#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->right = newNode->left = nullptr;
    return newNode;
}

bool isFullBinaryTree(Node *root)
{

    // Check if tree is empty
    if (root == nullptr)
        return true;

    // Check if tree has children
    if (root->left == nullptr && root->right == nullptr)
        return true;

    if ((root->left) && (root->right))
        return (isFullBinaryTree(root->left) && isFullBinaryTree(root->right));

    return false;
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    if (isFullBinaryTree(root))
    {
        cout << "Radi se o punom binarnom stablu \n";
    }
    else
    {
        cout << "Ne radi se o punom binarnom stablu \n";
    }
    return 0;
}