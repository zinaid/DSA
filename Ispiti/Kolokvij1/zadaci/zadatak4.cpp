#include <iostream>
using namespace std;

struct Node
{
    int vrijednost;
    Node *left;
    Node *right;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->vrijednost = value;
    newNode->left = newNode->right = nullptr;
    return newNode;
}

Node *insert(Node *root, int key)
{
    if (root == nullptr)
    {
        return createNode(key);
    }

    if (key < root->vrijednost)
        root->left = insert(root->left, key);
    else if (key > root->vrijednost)
        root->right = insert(root->right, key);

    return root;
}

void inorder(Node *root)
{
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->vrijednost << " ";
    inorder(root->right);
}

bool search(Node *root, int key)
{
    if (root == nullptr)
        return false;

    if (root->vrijednost == key)
        return true;

    if (key < root->vrijednost)
        return search(root->left, key);

    if (key > root->vrijednost)
        return search(root->right, key);
}

main()
{
    Node *root = nullptr;
    root = insert(root, 22);
    insert(root, 10);
    insert(root, 4);
    insert(root, 17);
    insert(root, 1);
    insert(root, 5);
    insert(root, 24);
    insert(root, 23);
    insert(root, 30);
    insert(root, 34);

    cout << "Inorder tree: " << endl;
    inorder(root);

    int key;
    cout << "\nUnesite kljuc: ";
    cin >> key;

    if (search(root, key))
    {
        cout << "Kljuc se nalazi u stablu" << endl;
    }
    else
    {
        cout << "Kljuc se ne nalazi u stablu" << endl;
    }
    return 0;
}