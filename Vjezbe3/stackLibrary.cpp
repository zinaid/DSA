#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;

    s.push(1);
    s.push(2);
    s.push(3);

    cout << "Stack size is " << s.size() << endl;

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }

    cout << "\nStack is empty now. Size is " << s.size() << endl;
    return 0;
}
