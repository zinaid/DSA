#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void printArray(const vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void selectionSort(vector<int> &vec)
{
    int minId;
    for (int i = 0; i < vec.size() - 1; i++)
    {
        minId = i;

        for (int j = i + 1; j < vec.size(); j++)
        {
            if (vec[j] < vec[minId])
            {
                minId = j;
            }
        }

        swap(vec[i], vec[minId]);
    }
}

int main()
{
    vector<int> vec = {1, 2, 5, 3, 7, 11, 5, 3};

    cout << "Prije sortiranja: " << endl;
    printArray(vec);

    selectionSort(vec);

    cout << "\nPoslije sortiranja: " << endl;
    printArray(vec);

    return 0;
}