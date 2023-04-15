# BINARNO STABLO PRETRAGE BST

Binarno stablo pretrage je struktura podataka koja omogućuje brzo pretraživanje sortirane liste brojeva.

Zove se binarno jer svaki čvor ima maksimum dvoje djece. Naziva se drvo za pretragu jer se koristi za pretragu brojeva u O(log(n)) vremenu.

Osobine koje odvajaju binarno stablo pretrage od regularnog binarnog stabla su:

Svi čvorovi lijevog podstabla su manji od korijenskog čvora

Svi čvorovi desnog podstabla su veći od korijenskog čvora

Oba podstabla svakog čvora su isto BST.

Primjer operacija kreiranja, dodavanja, brisanja i pretrage je dat sa primjerom bst.cpp.

Vremenska kompleksnost:

<table>
    <th>Operacija</th>
    <th>Najbolji slucaj</th>
    <th>Prosjecni slucaj</th>
    <th>Najgori slucaj</th>
    <tr>
    <td>Pretraga</td>
    <td>O(log n)</td>
    <td>O(log n)</td>
    <td>O(n)</td>
    </tr>
    <tr>
    <td>Dodavanje</td>
    <td>O(log n)</td>
    <td>O(log n)</td>
    <td>O(n)</td>
    </tr>
    <tr>
    <td>Brisanje</td>
    <td>O(log n)</td>
    <td>O(log n)</td>
    <td>O(n)</td>
    </tr>
</table>

Vremenska kompleksnost svih operacija je O(n).

Binarno stablo pretrage se koristi u:

* indeksiranju baza

* dinamičkog sortiranja

* upravljanje sa virtualnom memorijom