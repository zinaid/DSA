# BINARNO STABLO PRETRAGE BST

Binarno stablo pretrage je struktura podataka koja omogućuje brzo pretraživanje sortirane liste brojeva.

Zove se binarno jer svaki čvor ima maksimum dvoje djece. Naziva se drvo za pretragu jer se koristi za pretragu brojeva u O(log(n)) vremenu.

Osobine koje odvajaju binarno stablo pretrage od regularnog binarnog stabla su:

Svi čvorovi lijevog podstabla su manji od korijenskog čvora

Svi čvorovi desnog podstabla su veći od korijenskog čvora

Oba podstabla svakog čvora su isto BST

Dvije osnovne operacije nad BST su:
Pretraga i Insert.

## Pretraga

Algoritam ovisi o osobinama BST-a tj da svako lijevo podstablo ima manje vrijednosti i svako desno podstablo ima veće vrijednosti od korijena.

Ako je vrijednost ispod čvora, sa sigurnošću znamo da se ne nalazi u desnom podstablu i gledamo samo lijevo. 

### Algoritam

```
If root == NULL
    return NULL;
If number == root->data
    return root->data
If number < root->data
    return search(root->left)
If number > root->data
    return search(root->right)
```
