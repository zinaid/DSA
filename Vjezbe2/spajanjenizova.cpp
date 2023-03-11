#include <iostream>
using namespace std;

const int MAX_SIZE = 100;

void create_third_array(int arr1[], int size1, int arr2[], int size2, int result[], int &size_result)
{
    //  početna vrijednost veličine niza, iterativna varijabla
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
    int arr1[] = {1, 2, 3};
    int size1 = 3;

    int arr2[] = {4, 5, 6};
    int size2 = 3;

    int result[MAX_SIZE];
    int size_result;

    create_third_array(arr1, size1, arr2, size2, result, size_result);

    cout << "Rezultat: ";
    for (int i = 0; i < size_result; i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;

    return 0;
}
