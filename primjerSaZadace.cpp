#include <iostream>
#include <fstream>

using namespace std;

struct Knjiga {
    int id;
    string naziv, autor;
    int godina;
};

void dodajKnjigu(){
    Knjiga knjiga;
    ofstream fajl;

    fajl.open("knjige.txt", ios::app);

    if(!fajl){
        cout<<"Fajl nije ok"<<endl;
        return;
    }

    cout<<"Unesite id knjige"<<endl;
    cin>>knjiga.id;

    cout<<"Unesite naziv knjige"<<endl;
    cin>>knjiga.naziv;

    cout<<"Unesite autora knjige"<<endl;
    cin>>knjiga.autor;

    cout<<"Unesite godinu knjige"<<endl;
    cin>>knjiga.godina;

    fajl<<knjiga.id<<"|"<<knjiga.naziv<<"|"<<knjiga.autor<<"|"<<knjiga.godina<<endl;

    cout<<"Knjiga je uspjesno dodana"<<endl;

    fajl.close();
}

void ispisiKnjige(){
    ifstream fajl;
    fajl.open("knjige.txt", ios::in);

    if(!fajl){
        cout<<"Greska"<<endl;
        return;
    }

    string linija;

    while (getline(fajl, linija)) {
        cout << linija << endl;
    }
}

void pretraziKnjigu(){
    string trazenoIme;
    Knjiga knjiga;

    ifstream fajl;
    fajl.open("knjige.txt", ios::in);

    if(!fajl){
        cout<<"Greska"<<endl;
        return;
    }

    cout<<"Unesite ime knjige"<<endl;
    cin>>trazenoIme;

    while(fajl){
        fajl>>knjiga.id;
        fajl.ignore();              
        getline(fajl, knjiga.naziv, '|');
        getline(fajl, knjiga.autor, '|');
        fajl >> knjiga.godina;

        if(knjiga.naziv == trazenoIme){
            cout<<"Nadjeno"<<endl;
            return;
        }
    }
}


int main(){

    int opcija = 0;

    do{
        cout<<"MENI"<<endl;
        cout<<"1. DODAJ KNJIGU"<<endl;
        cout<<"2. ISPISI KNJIGE"<<endl;
        cout<<"3. PRETRAZI KNJIGU"<<endl;
        cout<<"-1 JE IZLAZAK IZ MENIJA"<<endl;
        cin>>opcija;

        switch(opcija){
            case 1:
                dodajKnjigu();
            break;

            case 2:
                ispisiKnjige();
            break;

            case 3:
                pretraziKnjigu();
            break;

            default:
                cout<<"Unijeli ste pogresnu opciju"<<endl;
            break;
        }
    }while(opcija != -1);


    return 0;
}