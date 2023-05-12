# MERGE SORT

Merge sort je jedan od najpopularnijih sorting algoritama baziran na principu Podjeli pa vladaj.

Problem se dijeli na više podproblema. Svaki podproblem se riješava individualno. Na kraju, podproblemi se kombiniraju u finalno rješenje.

<img src="images/merge1.png" />

Podjeli pa vladaj strategija:

Koristeći podjeli pa vladaj tehniku, probleme dijelimo u podprobleme. Kada se pronađe rješenje za svaki podproblem, kombiniramo rezultat iz podproblema i formiramo finalno rješenje.

Zamislimo da trebamo sortirati niz A. Podproblem bi bio da sortiramo sekciju ovog niza startajući od indeksa p i završavajući na indeksu r, označavajući to kao A[p...r].

Podjeli:

Ako je q, tačka na pola između p i r, onda možemo podijeliti podniz A[p...r] u dva niza A[p...q] i A[q+1...r].

Osvoji:

U conquer koraku, mi sortiramo oba podniza A[p...q] i A[q+1...r]. Ako još nismo došli do baznog slučaja, ponovno dijelimo i ove podnizove i pokušavamo ih sortirati.

Kombiniraj:

Kad conquer korak dođe do baznog koraka i dobijemo dva sortirana podniza A[p...q] i A[q+1...r] za niz A[p...r], kombiniramo rezultate kreirajući sortirani niz A[p...r] od dva podniza A[p...q] i A[q+1...r].

## Merge Sort Algoritam

MergeSort funkcija kontinuirano dijeli niz u dvije pole dok ne dođe do faze gdje pokušavamo odraditi MergeSort na podnizu veličine 1.

Poslije toga, merge funkcija kombinira sortirane nizove u veće nizove dok se cijeli niz ne merga.

```
MergeSort(A, p, r):
    if p > r 
        return
    q = (p+r)/2
    mergeSort(A, p, q)
    mergeSort(A, q+1, r)
    merge(A, p, q, r)
```

Da bi sortirali cijeli niz, moramo pozivati MergeSort(A, 0, length(A)-1).

<img src="images/merge9.png" />

Kao što se vidi na slici, merge sort algoritam rekurzivno dijeli algoritam na polovice dok ne dođe do baznog slučaja niza sa 1 elementom. Poslije toga, merge funkcija kupi sortirane podnizove i spaja ih i formira sortiran cijeli niz.



