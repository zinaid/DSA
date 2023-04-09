#include <iostream>
#include <string>
#include <map>
using namespace std;

int main()
{
    map<string, string> mojaMapa;
    mojaMapa.insert(make_pair("key1", "10"));
    mojaMapa["key2"] = "20";

    cout << "Velicina mape je: " << mojaMapa.size() << endl;

    for (auto pair : mojaMapa)
    {
        cout << pair.first << " " << pair.second << endl;
    }

    // Brisanje elementa
    mojaMapa.erase("key1");
    cout << "Velicina mape je: " << mojaMapa.size() << endl;

    // Pražnjenje mape
    mojaMapa.clear();
    return 0;
}