# DATOTEKE U C++

Biblioteka fstream omogućava nam rad sa fajlovima.

Da bi koristili fstream biblioteku, uključimo i iostream i fstream header fajlove.

```c++
#include <iostream>
#include <fstream>
```

U ovoj biblioteci imaju tri klase koje se koriste za kreiranje, čitanje ili pisanje fajlova.

ofstream - kreiranje i pisanje u fajlove
ifstream - čitanje iz fajlova
fstream - kombinacija kreiranja, čitanja i pisanja u fajlove

### KREIRANJE I PISANJE U FAJL

Nakon uključivanja fstream biblioteke, koristimo nekoliko njenih funkcionalnosti i tipova.

Prije svega potrebno je deklarirati fstream tip.

```c++
#include <iostream>
#include <fstream>
using namespace std;
int main(){
    fstream myFile;
    // ako ne postoji kreirat ce ga
    myFile.open("fajl.txt", ios::out); // write

    // provjera da li je fajl uspjesno ostvoren
    if(myFile.is_open()){
        myFile<<"Hello \n";
        myFile<<"Hello 2 \n";
    }

    // obavezno zatvarati fajl
    myFile.close();

    return 0;
}
```

Zamislimo situaciju da sad želimo uraditi append na trenutni postojeći fajl.

Zamislimo sljedeću situaciju:
```c++
#include <iostream>
#include <fstream>
using namespace std;

int main(){
    fstream fajl;
    fajl.open("fajl.txt", ios::out);

    if(fajl.is_open()){
        fajl<<"Hello 3\n";
    }

    fajl.close();
    return 0;
}

```
Ovaj kod će nam prekucati postojeće stanje u txt fajlu. Ako želimo uraditi append moramo koristiti mode append.

```c++
fajl.open("fajl.txt", ios::app);
```

### ČITANJE IZ FAJLA

Prvi korak je otvaranje fajla u read modu. Zatim sa while petljom prolazimo kroz cijeli sadrzaj fajla.


```c++
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    fstream fajl;
    fajl.open("fajl.txt", ios::in);

    if (fajl.is_open())
    {
        string line;
        while (getline(fajl, line))
        {
            cout << line << endl;
        }
    }

    fajl.close();
    return 0;
}
```

Koristimo i string biblioteku da možemo koristiti getline funkciju.