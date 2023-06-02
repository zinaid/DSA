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
    newNode->right = newNode->left = NULL;
    return newNode;
}

// Funkcija za brojanje cvorova
int countNumNodes(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + countNumNodes(root->left) + countNumNodes(root->right));
}

bool checkComplete(Node *root, int index, int numberNodes)
{
    if (root == NULL)
        return true;

    if (index >= numberNodes)
        return false;

    return (checkComplete(root->left, 2 * index + 1, numberNodes) && checkComplete(root->right, 2 * index + 2, numberNodes));
}

int main()
{
    Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);

    int node_count = countNumNodes(root);
    int index = 0;

    if (checkComplete(root, index, node_count))
        cout << "Radi se o kompletnom binarnom stablu \n";
    else
        cout << "Ne radi se o kompletnom binarnom stablu \n";
}
