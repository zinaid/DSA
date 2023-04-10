# KRUŽNA LISTA

<img src="../images/kruznalista.png" />

Kružna povezana lista je varijacija povezane liste u kojoj je zadnji element povezan sa prvim elementom. Ova forma daje kružnu petlju.

Kružne povezane liste mogu biti jednostruko ili dvostruko povezane.

Kod jednostruko povezane, sljedeći pokazivač zadnjeg čvora pokazuje na prvi čvor.

<img src="../images/kruznajednostruka.png" />

U dvostrukoj, prethodni pokazivač prvog čvora pokazuje na zadnji čvor.

<img src="../images/kruznadvostruka.png" />

Jednostavnu implementaciju kružne liste moguće je vidjeti na primjeru ```circularlistexample1.cpp```.

## Operacije sa kružnom listom:

Dodavanje na početak

<img src="images/dodavanjenapocetak.png">

Dodavanje na kraj

<img src="images/dodavanjenakraj.png">

Dodavanje na poziciju

<img src="images/dodavanjenapoziciju.png">

Brisanje čvorova:

Ako je jedini element

Ako je element koji se briše jedini čvor. Oslobodi se memorija okupirana od čvora i spremi se NULL za zadnji.

Brisanje sa kraja

<img src="images/brisanjesakraja.png">

Brisanje sa pozicije

<img src="images/brisanjesapozicije.png">

Vremenska kompleksnost dodavanja elemenata je O(1) ili O(n). Brisanja je O(1). Prostorna kompleksnost je O(1) za dodavanje i brisanje.

Kod kružnih lista ne treba dodjeljivanje NULL vrijednosti jer čvor uvijek pokazuje na sljedeći. Početna tačka može biti bilo koji čvor. Prolazak od prvog do zadnjeg čvora je brz.

Primjenjuju se u multiplayer igricama za dodjelu igrača. Razne aplikacije u OS sistemu mogu se spremiti u kružnu listu gdje OS vrši iteraciju kroz ove aplikacije.