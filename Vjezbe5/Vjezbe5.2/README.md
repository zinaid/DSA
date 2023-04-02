# DVOSTRUKO POVEZANE LISTE

Dvostruko povezana lista je tip liste kod koje se svaki čvor sastoji od tri komponente.

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
