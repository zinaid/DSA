#include <iostream>
using namespace std;

int main()
{
    int n;

    struct Student
    {
        char ime[50], prezime[50];
        int godine;
        float prosjek;
    };

    cout << "Unesite broj studenata: ";
    cin >> n;

    Student studenti[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Unesite ime " << i << "."
             << " studenta: ";
        cin >> studenti[i].ime;
        cout << "Unesite prezime " << i << "."
             << " studenta: ";
        cin >> studenti[i].prezime;
        cout << "Unesite godine " << i << "."
             << " studenta: ";
        cin >> studenti[i].godine;
        cout << "Unesite prosjek " << i << "."
             << " studenta: ";
        cin >> studenti[i].prosjek;
    }

    int maxIndex;
    float max = 0;
    for (int j = 0; j < n; j++)
    {
        if (studenti[j].prosjek >= max)
        {
            max = studenti[j].prosjek;
            maxIndex = j;
        }
    }

    cout << "Najveci prosjek je: " << max << endl;
    cout << "Student sa najvećim prosjekom je: " << studenti[maxIndex].ime << studenti[maxIndex].prezime << endl;
    return 0;
}