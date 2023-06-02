# OPERACIJE SA POVEZANIM LISTAMA

Operacije nad listama su:
* Traversal - Prolazak kroz listu
* Insertion - Dodavanje u listu
* Deletion - Brisanje postojećeg elementa
* Search - Pronalazak čvora u povezanoj listi
* Sort - Sortiranje čvorova u povezanoj listi
  
Glava pokazuje na prvi čvor liste. Pokazivač *sljedeci pokazuje na sljedeći čvor povezane liste. Pokazivač *sljedeci zadnjeg čvora je NULL.

## TRAVERSAL - Prolazak kroz povezanu listu

Prikaz sadržaja liste je jednostavno. Pomjeramo temp čvor na sljedeći i prikazujemo sadržaj. Kad je temp jednak NULL/nullptr znači da smo došli do kraja liste i tad izlazimo iz while petlje.

```c++
struct Cvor *temp = glava;
cout<<"Elementi liste su \n";
while(temp != nullptr){
    cout<<temp->vrijednost;
    temp = temp->sljedeci;
}
```

## INSERT - Dodavanje elemenata u povezanu listu

Elementi se mogu dodati na početak, sredinu ili kraj povezane liste.

### Dodavanje na početak

Alociramo memoriju za novi čvor. Spremimo vrijednost. Promjenimo sljedeci novog čvora da pokazuje na glavu, a promjenimo da glava pokazuje na novi kreirani čvor.

```c++
struct Cvor *noviCvor = new Cvor;
noviCvor->vrijednost = 4;
noviCvor->sljedeci = glava;
glava = noviCvor;
```

### Dodavanje na kraj

Alociramo memoriju za novi čvor. Spremimo vrijednost. Dođemo do zadnjeg čvora (Traverse) prolaskom kroz listu. Promjenimo next zadnjeg čvora da pokazuje na novokreirani čvor. Novi čvor treba da pokazuje na nullptr jer je on sad zadnji. 

```c++
struct Cvor *noviCvor = new Cvor;
noviCvor->vrijednost = 4;
noviCvor->sljedeci = nullptr;

struct Cvor *temp = glava;
while(temp->sljedeci != nullptr){
    temp = temp->sljedeci;
}

temp->sljedeci = noviCvor;

```

### Dodavanje u sredinu

Alociramo memoriju i spremimo vrijednost za novi čvor. Prođemo kroz listu (Traverse) do čvora koji je na poziciji prije pozicije novog čvora koji želimo dodati. Promjenimo pokazivač tog čvora do kojeg smo došli da pokazuje na novokreirani čvor. Novokreirani čvor će pokazivati na sljedeci od temp čvora kojeg smo našli na poziciji poslije koje želimo dodati naš novi čvor. A taj temp->sljedeci ce sad pokazivati na noviCvor.

```c++
struct Cvor *noviCvor = new Cvor;
noviCvor->vrijednost = 4;

struct Cvor *temp = glava;
for (int i=2; i<pozicija; i++){
    if(temp->sljedeci != nullptr){
        temp = temp->sljedeci;
    }
}
noviCvor->sljedeci = temp->sljedeci;
temp->sljedeci = noviCvor;
```

## Brisanje iz povezane liste

Brisanje se može odraditi sa početka, kraja ili iz neke određene pozicije.

### Brisanje sa početka

Glava se postavi da pokazuje na drugi čvor.

```c++
glava = glava->sljedeci;
```

### Brisanje sa kraja

Prođemo kroz listu do predzadnjeg elementa i postavimo njegov sljedeći pokazivač na nullptr.

```c++
struct Cvor *temp=glava;
while(temp->sljedeci->sljedeci != nullptr){
    temp = temp->sljedeci;
}
temp->sljedeci = nullptr;
```

### Brisanje sa pozicije

Prođemo kroz listu do elementa koji se nalazi na poziciji prije elementa koji se treba obrisati. Promjenimo sljedeci pokazivac da isključimo čvor iz lanca.

```c++
for(int i=2;i<pozicija;i++){
    if(temp->sljedeci != nullptr){
        temp = temp->sljedeci;
    }
}

temp->sljedeci = temp->sljedeci->sljedeci;

```

## Pretraga elementa u povezanoj listi

Elementi se mogu pretraživati na povezanoj listi koristeći petlje prateći sljedeće korake. Recimo da tražimo neki element u povezanoj listi.

Napravi se novi temp čvor koji pokazuje na glavu. Prolazi se kroz listu sve dok je temp != nullptr. U svakoj iteraciji gledamo da li je vrijednost tog čvora jednaka traženom elementu i ako jest radimo return, suprotno povećavamo temp.

```c++
bool pretragaCvora(struct Cvor** glava, int element){
    struct Cvor*temp = *glava;
    while(temp != NULL){
        if(temp->vrijednost == element){
            return true;
        }
        temp = temp->sljedeci;
    }
    return false;
}
```
```
NAPOMENA: Dupli asterisk ** označava pokazivač na pokazivač. To znači da varijabla čuva memorijsku adresu drugog pokazivača. Obzirom da je glava pokazivač koji pokazuje na prvi čvor liste, promjena njegove vrijednosti zahtjeva modificiranje vrijednosti pokazivača, ne samo vrijednosti čvora na koji pokazuje. Zbog toga, dupli pokazivač se koristi za dozvolu promjena na pokazivač "glavu" direktno.

Koristeći * ispred glave, dereferenciramo vrijednost pokazivača da bi dobili vrijednost pokazivača na prvi čvor, što je isto pokazivač.

```