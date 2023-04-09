#include <iostream>
using namespace std;

int kvadriraj(int n);

int main()
{
    int n = 10;
    cout << kvadriraj(10);
    return 0;
}

int kvadriraj(int n)
{
    return n * n;
}