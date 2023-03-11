# NIZOVI

Niz je kolekcija elemenata spremljenih u graničnu memorijsku lokaciju. Ideja je da se spremi više elemenata istog tipa.

Niz je linearna struktura podataka koja sadržava isti tip podataka i sprema ih u granične (jedna za drugom) memorijske lokacije. Nizovi rade na indeks sistemu koji počinje od 0 do (n-1) gdje je n veličina niza.

Nizovi omogućuju da lakše održavamo podatke istog tipa i da ne trebamo praviti nove varijable za svakog novog člana niza.

Tipovi niza su:

1. JEDNODIMENZIONALNI NIZ [1-D]
2. VIŠEDIMENZIONALNI NIZ [2-d]

Niz deklariramo tako što naglasimo tip podaka niza, njegovo ime i dimenzije.

```c++
int niz[n];
int niz[][];
```

Niz inicijaliziramo tako što u vitičaste zagrade dodamo vrijednosti niza.

```c++
int niz[]={1,2,3,4};
```

Pristup članovima niza:

```c++

niz[0];

niz[2][3];

```


Prolazak kroz niz:

```c++
#include <iostream>
using namespace std;

int main(){
    int niz[]={1,2,3,4,5};

    for(int i=0;i<5;i++){
        cout<<niz[i];
    }

    return 0;
}
```

Dodavanje elemenata u niz:

Elemente možemo dodati na početak, na kraj ili bilo koju poziciju. Ali je bitno da novi nik nakon toga preuredimo.

Brisanje elemenata u nizu:

Proces brisanja elemenata se sastoji u tome da uklonimo element na nekoj poziciji, pa reorganiziramo niz. Moguće je raditi na početku, na poziciji ili na kraju.

Ovdje ćemo implementirati primjer algoritma za brisanje člana na nekoj poziciji.

```
1. Start
2. Postavi J = K
3. Ponovi korake 4 i 5 dok je J < N
4. Postavi LA[J] = LA[J + 1]
5. Postavi J = J+1
6. Postavi N = N-1
7. Stop
```

```c++
#include <iostream>

using namespace std;

int main(){
    int n, pozicija;
    cout<<"Koliki niz hocete:\t";
    cin>>n;

    int niz[n];

    cout << "Unesite niz: " << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> niz[i];
    }

    cout<<"Koju poziciju zelite obrisati\t";
    cin>>pozicija;

    int j=pozicija;

    while(j<n){
        niz[j] = niz[j+1];
        j=j+1;
    }

    n=n-1;

    //ispisi niz

    return 0;
}
```

Pretraga niza:

Niz možemo pretraživati na više načina, a najpopularniji su linearna pretraga i binarna pretraga. O ovome će biti govora kad se budu obrađivali algoritmi pretrage.

Sortiranje niza:

Postoje razni algoritmi sortiranja niza, a o njima će biti govora kad se budu obrađivali algoritmi sortiranja.

Prednosti nizova:

Sadrži više elemenata istog tipa koristeći jedno ime. Moguće je lako pristupati elementima koristeći indekse. Memorija niza je predefinirana pa nema neočekivanih gubitaka memorije. Nizovi spriječavaju overflow memorije. 2D nizovi mogu lako predstavljati tabelarne podatke.

Nedostaci nizova:
Broj elemenata u nizu mora biti predefinisan.
Niz je statičan, ne može mijenjati svoju veličinu poslije deklaracije
Insert i brisanje u niz je poprilično nezgodno jer nizovi čuvaju elemente u kontinuiranoj formi.
Alokacija više memorije nego što treba je u suštini trošenje memorije.

Primjer 1.

Napraviti program koji računa sumu unešenog niza.

Primjer 2.

Napraviti program koji pronalazi najveći član niza i provjerava koliko se puta ponavlja.

Primjer 3.

Napraviti program koji vrši spajanje nizova koristeći dinamičke nizove.

Primjer 4.

Napraviti program koji računa faktorijel do nekog broja, koristeći nizove.

Primjer 5.

Napraviti program koji računa faktorijel do nekog broja koristeći rekurzivne funkcije.

Primjer 6.

Napraviti program u kojem korisnik unosi dvije matrice, sabira ih i ispisuje rezultat.

Primjer 7.

Napraviti program u kojem korisnik množi dvije matrice i ispisuje njihov rezultat.

Primjer 8.

Napraviti program u kojem korisnik unosi matricu i ispisuje elemente ispod glavne dijagonale.

