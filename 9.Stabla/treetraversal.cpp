#include <iostream>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

void inorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    inorderTraversal(node->left);
    cout << node->data << "->";
    inorderTraversal(node->right);
}

void preorederTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    cout << node->data << "->";
    preorederTraversal(node->left);
    preorederTraversal(node->right);
}

void postorderTraversal(Node *node)
{
    if (node == nullptr)
    {
        return;
    }

    postorderTraversal(node->left);
    postorderTraversal(node->right);
    cout << node->data << "->";
}

int main()
{
    Node *root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(4);
    root->left->left = createNode(5);
    root->left->right = createNode(6);

    cout << "Inorder traversal ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal ";
    preorederTraversal(root);
    cout << endl;

    cout << "Postorder traversal ";
    postorderTraversal(root);
    cout << endl;

    return 0;
}