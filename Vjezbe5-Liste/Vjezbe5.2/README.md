# DVOSTRUKO POVEZANE LISTE

Dvostruko povezana lista je tip liste kod koje se svaki čvor sastoji od tri komponente.

<img src="../images/doublelist.png" />

*prev - adresa prethodnog čvora
data - vrijednost
*next - adresa sljedećeg čvora

Primjer strukture:

```c++
struct Cvor {
    int vrijednost;
    struct Cvor *sljedeci;
    struct Cvor *prethodni;
}
```

Primjer na tri čvora vidjeti u zadatku ```doublelistexample1.cpp```.

Operacije nad dvostrukom listom su prikazane u zadatku ```doublelistexample2.cpp```.

Kompleksnost operacija koje ne trebaju prolazak kroz listu je O(1), a koje trebaju je O(n).

Dvostruko povezane liste se koriste kod:

UNDO i REDO operacija u softveru

Forward i Backward navigacije u browseru

Bilo kakvih navigacijskim sistemima kojima treba forward i backward
