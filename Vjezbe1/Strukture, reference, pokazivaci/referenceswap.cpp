#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int z = x;
    x = y;
    y = z;
}

int main()
{
    int firstNum = 10;
    int secondNum = 20;

    cout << "Prije zamjene: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";

    // Poziv funkcije sa parametrima
    swap(firstNum, secondNum);

    cout << "Poslije zamjene: "
         << "\n";
    cout << firstNum << " " << secondNum << "\n";

    return 0;
}