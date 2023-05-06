# LINEARNA PRETRAGA

Linearna pretraga je sekvencijalni algoritam pretrage gdje startamo od jednog kraja i provjeravamo svaki element liste, sve dok se ne nađe željeni element. To je najjednostavniji algoritam pretrage.

<img src="images/linear1.png">

Zamislimo da tražimo element 1.

<img src="images/linear2.png">

Startamo od prvog elementa i kompariramo k sa svakim elementom x.

<img src="images/linear3.png">

Ako je x==k vrati indeks tog elementa, suprotno element nije nađen.

## Algoritam

```
LinearSearch(array, key)
  for each item in the array
    if item == value
      return its index
```

## Kompleksnost linearne pretrage

Vremenska kompleksnost: O(n)

Prostorna kompleksnost: O(1)

## Primjena linearne pretrage

Za pretragu manjih nizova (< 100 elemenata).