#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &vec, int left, int mid, int right)
{
    int i, j, k;
    i = left;
    j = mid + 1;
    k = left;

    vector<int> temp;

    while (i <= mid && j <= right)
    {
        if (vec[i] <= vec[j])
        {
            temp.push_back(vec[i]);
            i++;
            k++;
        }
        else
        {
            temp.push_back(vec[j]);
            j++;
            k++;
        }
    }

    while (i <= mid)
    {
        temp.push_back(vec[i]);
        i++;
        k++;
    }

    while (j <= right)
    {
        temp.push_back(vec[j]);
        j++;
        k++;
    }

    // Moze ovako
    // for (int s = left; s <= right; s++)
    // {
    //     vec[s] = temp[s - left];
    // }

    copy(temp.begin(), temp.end(), vec.begin() + left);
}

void mergeSort(vector<int> &vec, int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(vec, left, mid);
        mergeSort(vec, mid + 1, right);
        merge(vec, left, mid, right);
    }
}

void printArray(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

int main()
{
    vector<int> vec = {1, 2, 4, 3, 1, 11, 6};

    cout << "Prije sortiranja: " << endl;
    printArray(vec);

    mergeSort(vec, 0, (vec.size() - 1));

    cout << "\n Poslije sortiranja: " << endl;
    printArray(vec);

    return 0;
}