#include <iostream>
using namespace std;

struct Cvor
{
    int key;
    Cvor *left;
    Cvor *right;
};

Cvor *createNode(int key)
{
    Cvor *newNode = new Cvor;
    newNode->key = key;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

Cvor *insert(Cvor *root, int key)
{
    if (root == nullptr)
        return createNode(key);

    if (key < root->key)
        root->left = insert(root->left, key);
    else if (key > root->key)
        root->right = insert(root->right, key);

    return root;
}

bool search(Cvor *root, int key)
{
    if (root == nullptr)
        return false;

    if (root->key == key)
        return true;

    if (key < root->key)
        return search(root->left, key);
    else
        return search(root->right, key);
}

void inorderTraversal(Cvor *root)
{
    if (root == nullptr)
        return;

    inorderTraversal(root->left);
    cout << root->key << " ";
    inorderTraversal(root->right);
}

int main()
{
    Cvor *root = nullptr;
    root = insert(root, 1);
    insert(root, 2);
    insert(root, 3);
    insert(root, 4);
    insert(root, 5);

    int key;
    cout << "Unesite kljuc: ";
    cin >> key;

    if (search(root, key))
        cout << "Kljuc " << key << " je u BST." << endl;
    else
        cout << "Kljuc " << key << " nije u BST." << endl;

    cout << "Inorder traversal of BST: ";
    inorderTraversal(root);
    cout << endl;

    return 0;
}
