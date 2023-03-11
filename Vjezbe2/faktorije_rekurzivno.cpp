#include <iostream>

using namespace std;

int faktorijel(int broj)
{
    if (broj > 1)
    {
        return (broj * faktorijel(broj - 1)); // korak rekurzije
    }
    else
        return 1; // uslov zaustavljanja rekurzije
}

int main()
{
    cout << "Unesi broj: ";
    int br;
    cin >> br;
    cout << "Faktorial broja: " << br << " je: " << faktorijel(br) << endl;
    system("pause");
}
