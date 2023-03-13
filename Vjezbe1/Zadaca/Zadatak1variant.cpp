/*
Implementirati funkciju

preko koje će se podaci iz strukture Zaposlenik čija je plata veća od 4000 KM spremiti u datoteku ime.txt, pri čemu je ime naziv zaposlenika.

Zaposlenici su sadrzani u fajlu zaposlenici.txt u formatu:

Zinaid Kapic Development 5000
John Doe Administration 2000

struct Zaposlenik{
    string ime;
    string prezime;
    string odjel;
    float plata;
}
*/

#include <iostream>
#include <fstream>
using namespace std;

struct Zaposlenik
{
    string ime;
    string prezime;
    string odjel;
    float plata;
};

bool checkFile(fstream &file);
void printZaposlenici(Zaposlenik zaposlenik[], int &numZaposlenici);
void saveZaposlenikWithBigPay(Zaposlenik zaposlenik[], int &numZaposlenici);

int main()
{
    int maxZaposlenika = 100;
    Zaposlenik zaposlenici[maxZaposlenika];

    fstream file;

    checkFile(file);

    int numZaposlenici = 0;

    while (numZaposlenici < maxZaposlenika && file)
    {
        Zaposlenik zaposlenik;
        file >> zaposlenik.ime >> zaposlenik.prezime >> zaposlenik.odjel >> zaposlenik.plata;
        if (file)
        {
            zaposlenici[numZaposlenici++] = zaposlenik;
        }
    }

    file.close();

    printZaposlenici(zaposlenici, numZaposlenici);

    saveZaposlenikWithBigPay(zaposlenici, numZaposlenici);

    return 0;
}

bool checkFile(fstream &file)
{
    file.open("zaposlenici.txt");

    if (!file.is_open())
    {
        throw runtime_error("Error opening file");
    }
    else
    {
        return true;
    }
}

void printZaposlenici(Zaposlenik zaposlenik[], int &numZaposlenici)
{
    for (int i = 0; i < numZaposlenici; i++)
    {
        cout << zaposlenik[i].ime << endl;
    }
}

void saveZaposlenikWithBigPay(Zaposlenik zaposlenik[], int &numZaposlenici)
{
    for (int i = 0; i < numZaposlenici; i++)
    {
        cout << "Tu0";

        if (zaposlenik[i].plata > 5000)
        {
            fstream file;
            file.open(zaposlenik[i].ime, ios::out);

            if (file.is_open())
            {
                file << zaposlenik[i].ime << zaposlenik[i].plata;
            }

            file.close();
        }
    }
}