#include <iostream>
using namespace std;

struct Cvor
{
    int vrijednost;
    Cvor *lijevo;
    Cvor *desno;
};

// Kreiranje cvora
Cvor *noviCvor(int item)
{
    Cvor *noviCvor = new Cvor;
    noviCvor->vrijednost = item;
    noviCvor->lijevo = noviCvor->desno = NULL;
    return noviCvor;
}

// Inorder Traversal
void inorder(Cvor *root)
{
    if (root != NULL)
    {
        // Traverse left
        inorder(root->lijevo);

        // Traverse root
        cout << root->vrijednost << " -> ";

        // Traverse right
        inorder(root->desno);
    }
}

// Dodavanje cvora
Cvor *insert(Cvor *cvor, int vrijednost)
{
    // Prazno stablo
    if (cvor == NULL)
        return noviCvor(vrijednost);

    // Ako je vrijednost manja od cvora dodaj u lijevo podstablo, suprotno u desno
    if (vrijednost < cvor->vrijednost)
        cvor->lijevo = insert(cvor->lijevo, vrijednost);
    else
        cvor->desno = insert(cvor->desno, vrijednost);

    return cvor;
}

// Pronadji inorder nasljednika
Cvor *minValueNode(Cvor *node)
{
    Cvor *temp = node;

    // Nadji zadnji lijevi cvor
    while (temp && temp->lijevo != NULL)
        temp = temp->lijevo;

    return temp;
}

// Brisanje cvora
Cvor *deleteNode(Cvor *root, int vrijednost)
{
    // Prazno stablo
    if (root == NULL)
        return root;

    // Pronadji cvor za brisati
    if (vrijednost < root->vrijednost)
        root->lijevo = deleteNode(root->lijevo, vrijednost);
    else if (vrijednost > root->vrijednost)
        root->desno = deleteNode(root->desno, vrijednost);
    else
    {
        // Ako ima jedno ili nijedno dijete
        if (root->lijevo == NULL)
        {
            Cvor *temp = root->desno;
            free(root);
            return temp;
        }
        else if (root->desno == NULL)
        {
            Cvor *temp = root->lijevo;
            free(root);
            return temp;
        }

        // Ako cvor ima dvoje djece
        Cvor *temp = minValueNode(root->desno);

        // Place the inorder successor in position of the node to be deleted
        root->vrijednost = temp->vrijednost;

        // Delete the inorder successor
        root->desno = deleteNode(root->desno, temp->vrijednost);
    }
    return root;
}

int main()
{
    Cvor *root = NULL;
    root = insert(root, 8);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 10);
    root = insert(root, 14);
    root = insert(root, 4);

    cout << "Inorder traversal: ";
    inorder(root);

    cout << "\nAfter deleting 10\n";
    root = deleteNode(root, 10);
    cout << "Inorder traversal: ";
    inorder(root);
}