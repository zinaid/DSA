U C++ mapa je kontejner koji sprema podatke u ključ-vrijednost parove. Implementirana je kao balansirano binarno stablo za pretragu, što čini pretragu, insert i brisanje elemenata jako efikasnim.

Ključevi u mapi su uvijek unikatni i spremaju se u uređenom redoslijedu. To omogućuje pretragu elemenata po ključu lakšom (logaritamska kompleksnost). Vrijednosti mogu biti bilo kojeg tipa, uključujući i korisnički definirane klase.

Da bi u C++ koristili mape uključimo <map> header fajl.

```c++
#include <map>
using namespace std;

int main(){
    map<kljuc, vrijednost> nazivMape;
}
```

Ovdje, kljuc je tip podataka za kljuceve, a vrijednost je tip podatka za vrijednosti. Naprimjer ako želimo mapu gdje će ključevi biti stringovi, a vrijednosti integeri koristimo sljedeću sintaksu:

```c++
#include <map>
#include <string>
using namespace std;
int main(){
    map<string, int> mojaMapa;
}
```

Da bi dodali element u mapu, koristimo insert() funkciju:

```c++
mojaMapa.insert(make_pair("key1", 10));
```

key1 je ključ, a vrijednost je 10. Moguće je dodati element ili modificirati koristeći []:

```c++
mojaMapa["key2"]=20;
```

Elementu možemo pristupi na osnovu njegovog ključa sa:

```c++
int vrijednost = mojaMapa["kljuc2"];
```