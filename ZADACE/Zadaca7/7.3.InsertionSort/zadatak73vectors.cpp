#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void insertionSort(vector<int> &vec)
{
    for (int step = 1; step < vec.size(); step++)
    {
        int key = vec[step];
        int j = step - 1;

        while (key < vec[j] && j >= 0)
        {
            vec[j + 1] = vec[j];
            j--;
        }
        vec[j + 1] = key;
    }
}

int main()
{
    vector<int> vec = {1, 3, 2, 10, 11, 4};

    cout << "Prije sortiranja: ";
    printArray(vec);

    insertionSort(vec);

    cout << "\nPoslije sortiranja: ";
    printArray(vec);
    return 0;
}