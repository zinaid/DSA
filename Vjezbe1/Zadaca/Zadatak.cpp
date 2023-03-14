#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ZAPOSLENICI = 100;

struct Zaposlenik
{
    string ime;
    string prezime;
    string odjel;
    float plata;
};

void checkFile(fstream &file, const string &filename)
{
    file.open(filename, ios::in);
    if (!file.is_open())
    {
        throw runtime_error("Error opening file");
    }
}

int readNumZaposlenikaFromFile(Zaposlenik *zaposlenici, fstream &file)
{
    int numZaposlenici = 0;
    while (numZaposlenici < MAX_ZAPOSLENICI && file)
    {
        file >> zaposlenici[numZaposlenici].ime >> zaposlenici[numZaposlenici].prezime >> zaposlenici[numZaposlenici].odjel >> zaposlenici[numZaposlenici].plata;
        numZaposlenici++;
    }
    return numZaposlenici;
}

void printZaposlenici(const Zaposlenik *zaposlenici, int numZaposlenici)
{
    for (int i = 0; i < numZaposlenici; i++)
    {
        cout << zaposlenici[i].ime << endl;
    }
}

void saveZaposlenikWithBigPay(const Zaposlenik *zaposlenici, int numZaposlenici)
{
    for (int i = 0; i < numZaposlenici; i++)
    {
        if (zaposlenici[i].plata > 5000)
        {
            fstream file;
            file.open(zaposlenici[i].ime + ".txt", ios::out);
            if (file.is_open())
            {
                file << zaposlenici[i].ime << " " << zaposlenici[i].plata << endl;
            }
            file.close();
        }
    }
}

int main()
{
    Zaposlenik zaposlenici[MAX_ZAPOSLENICI];
    fstream file;
    checkFile(file, "zaposlenici.txt");
    int numZaposlenici = readNumZaposlenikaFromFile(zaposlenici, file);
    file.close();
    printZaposlenici(zaposlenici, numZaposlenici);
    saveZaposlenikWithBigPay(zaposlenici, numZaposlenici);
    return 0;
}