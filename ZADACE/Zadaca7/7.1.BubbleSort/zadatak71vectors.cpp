#include <iostream>
#include <vector>
using namespace std;

void printArray(vector<int> vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void bubbleSort(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
            }
        }
    }
}

void bubbleSortOptimized(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        bool swapped = false;

        for (int j = 0; j < vec.size() - i - 1; j++)
        {
            if (vec[j] > vec[j + 1])
            {
                swap(vec[j], vec[j + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;
    }
}

int main()
{
    vector<int> vec = {1, 3, 2, 5, 4};

    cout << "Prije sortiranja: " << endl;
    printArray(vec);

    bubbleSort(vec);

    cout << "Poslije sortiranja: " << endl;
    printArray(vec);

    return 0;
}