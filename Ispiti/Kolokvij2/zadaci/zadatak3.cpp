#include <iostream>
#include <vector>
using namespace std;

vector<int> enterVector();
int binarySearch(const vector<int> &vec, const int &target, int low, int high);
void mergeSort(vector<int> &vec, int left, int right);
void merge(vector<int> &vec, int left, int mid, int right);
void print(const vector<int> &vec);

int main()
{
    vector<int> vec;
    int target;

    vec = enterVector();
    print(vec);

    cout << "\nUnesite element koji zelite pronaci" << endl;
    cin >> target;

    mergeSort(vec, 0, vec.size() - 1);

    cout << "Sortirano: " << endl;
    print(vec);

    int pozicija = binarySearch(vec, target, 0, vec.size());

    if (pozicija != -1)
    {
        cout << "\nElement " << target << " se nalazi na poziciji: " << pozicija << endl;
    }
    else
    {
        cout << "\nElement nije prisutan." << endl;
    }

    return 0;
}

vector<int> enterVector()
{
    vector<int> vec;
    int element;
    cout << "Unesite elemente (unos traje dok ne unesete -1)" << endl;
    cin >> element;
    while (element != -1)
    {
        vec.push_back(element);
        cin >> element;
    }

    return vec;
}

void print(const vector<int> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << " ";
    }
}

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

int binarySearch(const vector<int> &vec, const int &target, int low, int high)
{
    if (high >= low)
    {
        int mid = low + (high - low) / 2;

        // Vrati mid ako je nadjen odmah na sredini
        if (vec[mid] == target)
            return mid;

        // Trazi lijevu polovicu
        if (vec[mid] > target)
            return binarySearch(vec, target, low, mid - 1);

        // Suprotno trazi desnu polovicu
        return binarySearch(vec, target, mid + 1, high);
    }

    return -1;
}
