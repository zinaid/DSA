# VEKTORI

Vektori se koriste za spremanje elemenata istih tipova podataka. Za razliku od nizova, veličina vektora može rasti dinamički. Odnosno moguće je mijenjati veličinu vektora tokom egzekucije programa po potrebi. 

Vektori su dio standardne C++ biblioteke. Za korištenje vektora, moramo uključiti vector header fajl u naš program.

```c++
#include <iostream>
```

## Deklaracija vektora

Vektor se deklarira na sljedeći način:

 ```c++
 std::vector<T> vector_name;
 ```

Type parametar <T> označava tip vektora. Može biti primitivni tip podatka kao što je int, char, float, itd.

```
vector<int> num;
```

## Inicijalizacija vektora

Postoje dva načina inicijalizacije vektora, a to su:

```c++
 vector<int> vector1 = {1, 2, 3, 4, 5};

 vector<int> vector2 {1, 2, 3, 4, 5};
 ```

 ili 

```c++
vector<int> vector3(5, 12);

vector<int> vector3 = {12, 12, 12, 12, 12};

```

## OSNOVNE OPERACIJE SA VEKTORIMA

Osnovne operacije sa vektorima su dodavanje elemenata, pristup elementima, promjena i uklanjanje elemenata.

### Dodavanje elemenata - push_back()

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Initial Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }
  
  // add the integers 6 and 7 to the vector
  num.push_back(6);
  num.push_back(7);

  cout << "\nUpdated Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  return 0;
}

```

### Pristup elementima vektora - at()

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Element at Index 0: " << num.at(0) << endl;
  cout << "Element at Index 2: " << num.at(2) << endl;
  cout << "Element at Index 4: " << num.at(4);

  return 0;
}
```

Dakle, koristimo at(indeks) za pristup elementima na određenom indeksu.

### Promjena elementa

Moguće je promjeniti element vektora koristeći at() funkciju,

3. Change Vector Element

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  cout << "Initial Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  // change elements at indexes 1 and 4
  num.at(1) = 9;
  num.at(4) = 7;

  cout << "\nUpdated Vector: ";

  for (const int& i : num) {
    cout << i << "  ";
  }

  return 0;
}
```

### Brisanje elementa

Da bi obrisali element koristimo pop_back() funkciju.

```c++
#include <iostream>
#include <vector>

using namespace std;

int main() {
  vector<int> prime_numbers{2, 3, 5, 7};
  
  // initial vector
  cout << "Initial Vector: ";
  for (int i : prime_numbers) {
    cout << i << " ";
  }

  // remove the last element
  prime_numbers.pop_back();

  // final vector
  cout << "\nUpdated Vector: ";
  for (int i : prime_numbers) {
    cout << i << " ";
  }
  
  return 0;
}
```

Druge funkcije za rad sa vektorima:

size()

clear()

front()

back()
			
empty()

capacity()


### C++ vektor iteratori

Vektor iteratori se koristi za pokazivanje na memorijsku adresu elementa vektora. Funkcioniraju kao pokazivači u C++.

Prave se na sljedeći način:

```c++
vector<T>::iterator iteratorName;
```

Naprimjer:

```c++
// iterator for int vector
vector<int>::iterator iter1;

// iterator for double vector
vector<double>::iterator iter2;
```

Inicijalizacija vektor iteratora se radi sa begin() i end() funkcijama. Begin funkcija vraća iterator koji pokazuje na prvi element vektora, dok end pokazuje na teoretski element koji dolazi poslije finalnog elementa vektora.

Begin ()

```c++
vector<int> num = {1, 2, 3};
vector<int>::iterator iter;

// iter points to num[0]
iter = num.begin();
```

End ()
```c++
// iter points to the last element of num
iter = num.end() - 1;
```

Primjer:

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  // declare iterator
  vector<int>::iterator iter;

  // initialize the iterator with the first element
  iter = num.begin();

  // print the vector element
  cout << "num[0] = " << *iter << endl;

  // iterator points to the 3rd element
  iter = num.begin() + 2;
  cout << "num[2] = " << *iter;

  // iterator points to the last element
  iter = num.end() - 1;
  cout << "num[4] = " << *iter;

  return 0;
}
```

Rezultat:

num[0] = 1
num[2] = 3
num[4] = 5

Ovdje smo deklarirali int vektor iterator naziva iter u cilju da ga koristimo sa vektorom num.

```c++
// declare iterator
vector<int>::iterator iter;
```

Onda smo inicijalizirali iterator da pokazuje na prvi element sa begin() funkcijom.

```c++
// initialize the iterator with the first element
iter = num.begin();
```

Zatim ispisali smo element dereferenciranjem iteratora:

```c++
// print the vector element
cout << "num[0] = " << *iter << endl;
```

Zatim smo isprintali treći element vektora mijenjajući vrijednost iter sa num.begin() + 2.

Na kraju, ispisali smo zadnji element vektora koristeći end() funkciju.


Primjer: Prolazak kroz vektore koristeći iteratore

```c++
#include <iostream>
#include <vector>
using namespace std;

int main() {
  vector<int> num {1, 2, 3, 4, 5};

  // declare iterator
  vector<int>::iterator iter;

  // use iterator with for loop
  for (iter = num.begin(); iter != num.end(); ++iter) {
    cout << *iter << "  ";
  }

  return 0;
}
```

Rezultat

1  2  3  4  5 

Ovdje smo koristili for petlju za inicijalizaciju i iteraciju koristeći iterativnu varijablu iter od početka vektora do kraja vektora koristeći funkcije begin() i end().

```c++
// use iterator with for loop
for (iter = num.begin(); iter != num.end(); ++iter) {
  cout << *iter << "  ";
}
```