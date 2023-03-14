#include <iostream>
#include <fstream>
using namespace std;

struct Zaposlenik
{
    int id;
    string name, lastname;
    double salary;
};

bool checkfile(fstream &file, string mode)
{
    if (mode == "in")
    {
        file.open("zaposlenici.txt", ios::in);
    }
    else if (mode == "out")
    {
        file.open("studenti.txt", ios::out);
    }

    if (!file.is_open())
    {
        throw runtime_error("Error opening file");
    }
    else
    {
        return true;
    }
}

void printZaposlenici(Zaposlenik *zaposlenici, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << zaposlenici[i].name << " " << zaposlenici[i].lastname << " " << zaposlenici[i].salary << endl;
    }
}

int main()
{

    const int maxNumber = 100;

    Zaposlenik *zaposlenici = new Zaposlenik[maxNumber];
    fstream file;
    checkfile(file, "in");

    int numZaposlenici = 0;

    while (numZaposlenici < maxNumber && file)
    {
        Zaposlenik zaposlenik;
        file >> zaposlenik.id >> zaposlenik.name >> zaposlenik.lastname >> zaposlenik.salary;
        if (file)
        { // check if read was successful
            zaposlenici[numZaposlenici++] = zaposlenik;
        }
    }

    printZaposlenici(zaposlenici, numZaposlenici);

    file.close();

    delete[] zaposlenici;

    return 0;
}