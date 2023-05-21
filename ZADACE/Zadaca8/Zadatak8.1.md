# Zadatak 8.1:
Napišite program koji vrši sekvencijalnu pretragu na vektoru stringova. Program treba korisniku omogućiti unos stringova. Zatim, program treba pitati korisnika da unese string koji traži u vektoru. Program treba ispisati da li je string pronađen u vektoru, i ako jeste, na kojoj poziciji se nalazi, ili ispisati poruku koja ukazuje da string nije prisutan u vektoru. Korisnik unosi stringove dok ne unese string done. Tada se prestaje sa unosom stringova, a pita se za unos stringa za pretragu.

Zahtjevi:

Unos stringova radite u funkciji 

vector<string> enterVector()

Implementirajte funkciju 

int sequentialSearch(const vector<string>& vec, const string& target)

 koja vrši sekvencijalnu pretragu.  Funkcija treba vratiti poziciju traženog stringa u vektoru ako je pronađen, ili -1 ako string nije prisutan. Koristite odgovarajuće operacije nad vektorom za unos podataka od korisnika i izvršavanje pretrage.