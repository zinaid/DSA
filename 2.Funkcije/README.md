# FUNKCIJE

Funkcija je blok koda koji se pokreće samo onda kad je pozvan. Funkciji se mogu proslijeđivati parametri. Funkcije se koriste za izvođenje nekih akcija i važne su za efektivno pisanje čitljivog i iskoristivog koda.

C++ ima već obezbjeđene predefinirane funkcije, kao što je i int main(). 

Ali i mi sami možemo praviti funkcije za određene akcije. 

Funkcija se deklarira tako što napišemo tip funkcije koje prati ime funkcije popraćeno zagradama.

```c++
void mojaFunkcija(){

}
```

Funkciju pozivamo tako što napišemo njen naziv popraćen zagradama.

```c++

void mojaFunkcija(){
    cout<<"Hello"<<endl;
}

int main(){
    mojaFunkcija();

    return 0;
}

```

Svaka funkcija se sastoji od dva dijela:
1. DEKLARACIJA
2. DEFINICIJA

Deklaracija je u suštini tip (return tip), ime funkcije i parametri ako ih ima. Definicija je tijelo funkcije (kod koji se treba odraditi).

Funkcija mora biti deklarirana iznad njenog poziva, ali njena definicija ne mora biti napisana.

```c++
#include <iostream>
using namespace std;

int kvadriraj(int n);

int main()
{
    int n = 10;
    cout << kvadriraj(10);
    return 0;
}

int kvadriraj(int n)
{
    return n * n;
}
```

Funkciji se mogu proslijediti informacije u vidu parametara. Parametri su imena pobrojana u definiciji funkcije, dok su argumenti stvarne vrijednosti proslijeđene funkciji. Parametri djeluju kao varijable unutar funkcije.

```c++
void functionName(parameter1, parameter2, parameter3) {
// kod
}
```

Funkcija može imati i defaultnu verziju parametra. To pišemo na sljedeći način:

```c++
void ispisDrzave(string country = "BiH") {
    cout << country << "\n";
}
```

Dakle, u slučaju da ne proslijedimo vrijednost države ova funkcija će se izvršiti i uzeti vrijednost BiH.

Kada koristimo ključnu riječ void kažemo da naša funkcijane ne treba imati return vrijednost, suprotno tome deklariramo funkciju sa odgovarajućim tipom kojeg želimo da vrati. Vrijednost koju funkcija vrati možemo spremiti u neku varijablu, možemo je ispisati ili koristiti u daljnjem procesu.

Funkciji možemo proslijeđivati i reference. Konkretan primjer je i zamjena vrijednosti dvije varijable. Gdje umjesto da funkcija zauzme u memoriji vrijednost za svoja dva parametra, ona koristi adresne vrijednosti već deklariranih varijabli iz funkcije koja ju poziva.

```c++
#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int firstNum = 10;
    int secondNum = 20;

    cout << "Prije zamjene: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";

    // Poziv funkcije sa parametrima
    swap(firstNum, secondNum);

    cout << "Poslije zamjene: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";

    return 0;
}
```

Funkciji možemo proslijeđivati i nizove.

```c++

#include <iostream>
using namespace std;

void ispisniza(int niz[5])
{
    for (int i = 0; i < 5; i++)
    {
        cout << niz[i];
    }
}

int main()
{
    // deklaracija niza
    int niz[] = {
        6,
        1,
        2,
        3,
        4};

    // poziv funkcije i proslijeđivanje niza
    ispisniza(niz);
}

```

### OVERLOADING FUNKCIJE

Sa overloading funkcije možemo koristiti jedno te isto ime funkcije, ali sa različitim parametrima.

```c++
int myFunction(int x)
float myFunction(float x)
double myFunction(double x, double y)
```

### REKURZIJA

Rekurzija je tehnika u kojoj funkcija zove sama sebe. Ovo pomaže u rješavanju složenih problema i smanjivanju istih na jednostavnije. 

Primjer. Fibonačijev niz.

```c++
#include <iostream>
using namespace std;

int fib(int x) {
   if((x==1)||(x==0)) {
      return(x);
   }else {
      return(fib(x-1)+fib(x-2));
   }
}
int main() {
   int x , i=0;
   cout << "Unesite granicu : ";
   cin >> x;
   cout << "\nFibonnaci Niz : ";
   while(i < x) {
      cout << " " << fib(i);
      i++;
   }
   return 0;
}
```
