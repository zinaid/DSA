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
    newNode->left = newNode->right = nullptr;
    return newNode;
}

bool checkHeightBalance(Node *root, int *height)
{
    int leftHeight = 0;
    int rightHeight = 0;
    int l = 0;
    int r = 0;

    if (root == nullptr)
    {
        *height = 0;
        return 1;
    }

    l = checkHeightBalance(root->left, &leftHeight);
    r = checkHeightBalance(root->right, &rightHeight);

    if (leftHeight > rightHeight)
    {
        *height = leftHeight + 1;
    }
    else
    {
        *height = rightHeight + 1;
    }

    if (abs(leftHeight - rightHeight) >= 2)
        return 0;

    else
        return l && r;
}

int main()
{
    int height = 0;

    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);

    if (checkHeightBalance(root, &height))
        cout << "Drvo je balansirano";
    else
        cout << "Drvo nije balansirano";
}