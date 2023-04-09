#include <iostream>
#include <map>
#include <string>
#include <list>
using namespace std;

int main()
{
    map<string, list<string>> narutoClans;

    list<string> Uchiha{"Itachi", "Sasuke", "Madara"};
    list<string> Uzumaki{"Naruto", "Nagato", "Karin"};
    list<string> Senju{"Hashirama", "Tobirama", "Tsunade"};

    narutoClans.insert(make_pair("Uchiha", Uchiha));
    narutoClans.insert(make_pair("Uzumaki", Uzumaki));
    narutoClans.insert(make_pair("Senju", Senju));

    for (auto pair : narutoClans)
    {
        cout << pair.first << endl;

        for (auto member : pair.second)
        {
            cout << member << ",";
        }

        cout << endl;
    }
}