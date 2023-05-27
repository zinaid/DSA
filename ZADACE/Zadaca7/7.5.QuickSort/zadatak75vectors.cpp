#include <iostream>
#include <vector>
using namespace std;

void printArray(const vector<int> &vec)
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

int partition(vector<int> &vec, int start, int end)
{
    int pivot = vec[end];
    int partitionIndex = start;

    for (int i = start; i < end; i++)
    {
        if (vec[i] <= pivot)
        {
            swap(vec[i], vec[partitionIndex]);
            partitionIndex++;
        }
    }

    swap(vec[end], vec[partitionIndex]);

    return partitionIndex;
}

void quickSort(vector<int> &vec, int start, int end)
{
    if (start < end)
    {
        int partitionIndex = partition(vec, start, end);
        quickSort(vec, start, partitionIndex - 1);
        quickSort(vec, partitionIndex + 1, end);
    }
}

int main()
{
    vector<int> vec = {1, 2, 5, 3, 9, 7};

    cout << "Prije sortiranja: " << endl;
    printArray(vec);

    quickSort(vec, 0, vec.size() - 1);

    cout << "\nPoslije sortiranja: " << endl;
    printArray(vec);

    return 0;
}