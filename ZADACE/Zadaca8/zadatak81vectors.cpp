#include <iostream>
#include <vector>
#include <string>
using namespace std;

int sequentialSearch(const vector<string> &vec, const string &target)
{
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] == target)
        {
            return i;
        }
    }
    return -1;
}

vector<string> enterVector()
{
    vector<string> vec;
    cout << "Enter the strings (enter 'done' to stop):" << endl;
    string str;
    cin >> str;
    while (str != "done")
    {
        vec.push_back(str);
        cin >> str;
    }
    return vec;
}

int main()
{
    vector<string> vec = enterVector();

    string searchStr;
    cout << "Enter a string to search for: ";
    cin >> searchStr;

    int position = sequentialSearch(vec, searchStr);
    if (position != -1)
    {
        cout << "String '" << searchStr << "' is found at position " << position << "." << endl;
    }
    else
    {
        cout << "String '" << searchStr << "' is not found in the vector." << endl;
    }

    return 0;
}