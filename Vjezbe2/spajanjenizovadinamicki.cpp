#include <iostream>
using namespace std;

void create_third_array(int *arr1, int size1, int *arr2, int size2, int *&result, int &size_result)
{
    // Alokacija memorije za novi niz
    result = new int[size1 + size2];

    // Inicijalna velicina, iterativna varijabla
    size_result = 0;

    // Prolazak kroz prvi niz
    for (int i = 0; i < size1; i++)
    {
        result[size_result] = arr1[i];
        size_result++;
    }

    // Prolazak kroz drugi niz
    for (int i = 0; i < size2; i++)
    {
        result[size_result] = arr2[i];
        size_result++;
    }
}

int main()
{
    int size1 = 3;
    int *arr1 = new int[size1]{1, 2, 3};

    int size2 = 3;
    int *arr2 = new int[size2]{4, 5, 6};

    int *result;
    int size_result;

    create_third_array(arr1, size1, arr2, size2, result, size_result);

    cout << "Rezultat: ";
    for (int i = 0; i < size_result; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    // Frisanje nizova i čišćenje memorije
    delete[] arr1;
    delete[] arr2;
    delete[] result;

    return 0;
}
