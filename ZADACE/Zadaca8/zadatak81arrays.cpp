#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 100;

int sequentialSearch(const string arr[], int size, const string &target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            return i;
        }
    }
    return -1;
}

void enterArray(string arr[], int &size)
{
    cout << "Enter the number of strings: ";
    cin >> size;

    cout << "Enter the strings: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}

int main()
{
    string arr[MAX_SIZE];
    int size;

    enterArray(arr, size);

    string searchStr;
    cout << "Enter a string to search for: ";
    cin >> searchStr;

    int position = sequentialSearch(arr, size, searchStr);
    if (position != -1)
    {
        cout << "String '" << searchStr << "' is found at position " << position << "." << endl;
    }
    else
    {
        cout << "String '" << searchStr << "' is not found in the array." << endl;
    }

    return 0;
}
