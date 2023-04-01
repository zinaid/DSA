#include <iostream>
using namespace std;

// Struktura Cvor koja sadrzi vrijednost cvora i pokazivac tipa Cvor na sljedeci cvor
struct Cvor
{
    int vrijednost;
    Cvor *sljedeci;
};

// Inicijalno Cvor glava je NULL tj lista je prazna
Cvor *glava = nullptr;

// Funkcija za dodavanje cvora prima vrijednost koju treba dodati.
// Deklarira novi Cvor, da mu vrijednost i stavi da novi cvor pokazuje na NULL tj kraj liste
void dodajCvor(int vrijednost)
{
    Cvor *noviCvor = new Cvor();
    noviCvor->vrijednost = vrijednost;
    noviCvor->sljedeci = nullptr;
    // Ako je glava NULL znaci da je glava jednaka tom novom cvoru
    if (glava == nullptr)
    {
        glava = noviCvor;
    }
    // Suprotno prolazimo kroz cijelu listu startajuci od glave sve dok ne dodje do nula tj kraja.
    // Kad dodje do kraja znaci da je temp zadnji cvor u listi i on pokazuje sad na noviCvor
    else
    {
        Cvor *temp = glava;
        while (temp->sljedeci != nullptr)
        {
            temp = temp->sljedeci;
        }
        temp->sljedeci = noviCvor;
    }
}

// Funkcija za ispis liste, inicijalizira prvi cvor kao glavu i onda prolazi kroz listu tako da u svakoj iteraciji temp ima vrijednost sljedeceg elementa
// Kad se dodje da je temp jednako NULL doslo se do kraja
void ipisiListu()
{
    Cvor *temp = glava;
    while (temp != nullptr)
    {
        cout << temp->vrijednost << " ";
        temp = temp->sljedeci;
    }
}

int main()
{
    dodajCvor(1);
    dodajCvor(2);
    dodajCvor(3);
    dodajCvor(4);
    ipisiListu();
    return 0;
}