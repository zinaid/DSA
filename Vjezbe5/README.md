# LISTE

Povezana lista je linearna struktura podataka koja sadrži seriju povezanih čvorova. Svaki čvor sadrži podatak i adresu sljedećeg čvora.

Adresa prvog čvora nosi specijalno ime HEAD. Zadnji čvor u listi pokazuje na NULL.

Povezane liste mogu biti: jednostruke, dvostruke i kružne povezane liste.

## REPREZENTACIJA POVEZANIH LISTI

Svaki čvor u povezanoj listi se sastoji od:
* vrijednost (data)
* adrese sljedećeg čvora

```c++

struct Cvor
{
    int vrijednost;
    struct Cvor *sljedeci;
};

```

Svaka struktura Node ima podatak (data) i pokazivač na drugu strukturu Node.

Primjer povezane liste sa tri elementa:

```c++
    // Inicijalizacija cvorova
    struct Cvor *glava;
    struct Cvor *prvi = nullptr;
    struct Cvor *drugi = nullptr;
    struct Cvor *treci = nullptr;

    // Alociraj memoriju
    prvi = new Cvor;
    drugi = new Cvor;
    treci = new Cvor;

    // Dodijeli vrijednosti elementima
    prvi->vrijednost = 1;
    drugi->vrijednost = 2;
    treci->vrijednost = 3;

    // Spoji cvorove
    prvi->sljedeci = drugi;
    drugi->sljedeci = treci;
    treci->sljedeci = nullptr;

    // Spremi adresu prvog clana u glavu
    glava = prvi;
```

```**NAPOMENA: U C++ programskom jeziku, memorijska alokacija za dinamičke strukture podataka, kao što su liste se radi sa "new" funkcijom. Kad se pravi povezana lista, treba alocirati memoriju za svaki čvor dinamički zato što se veličina povezane liste mjenja tokom izvršavanja. Ne možemo alovirati memoriju za sve moguće čvorove unaprijed jer ne znamo veličinu liste. Svaki čvor se mora dinamički alocirati tako da se povezana lista može povećavati ili smanjivati. Veličina memorijskog bloka se odredi sa sizeof(struct Cvor);``` 

U prethodnom primjeru smo napravili jednostavnu povezanu listu sa tri čvora. Svaki čvor pokazuje na adresu sljedećeg čvora. Zadnji pokazuje na NULL, a prvi na glavu.

Snaga povezanih lista je u mogućnosti razbijanja i spajanja lanca. Naprimjer ako želimo staviti element 4 između 1 i 2 koraci bi bili:

Napravi novu strukturu čvora i alociraj mu memoriju. Dodijeli vrijednost npr. na 4. Stavi da njegov sljedeci pokazivac pokazuje na cvor "drugi". Promjeni sljedeci pokazivac od cvora "prvi" da pokazuje na čvor koji smo upravo napravili. Ovakvo nešto u nizovima bi zahtjevalo promjenu pozicija svih drugih elemenata.

Kompleksnost povezane liste:

Dodavanje i brisanje O(1), pretraga O(n).

Primjena povezanih lista:

* Dinamička memorijska alokacija,
* Implementacija steka i reda
* Undo funkcionalnosti u softvera
* Hash tabele i grafovi