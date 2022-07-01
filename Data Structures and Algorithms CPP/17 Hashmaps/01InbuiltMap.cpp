#include <iostream>
#include <string>
#include <utility>
#include <unordered_map>
using namespace std;

int main()
{
    unordered_map<string, int> map1;

    // insert
    pair<string, int> p1("abc", 1);
    map1.insert(p1);
    map1["def"] = 2;

    // access
    cout << map1["abc"] << " " << map1.at("abc") << "\n";
    // cout << map1.at("ghi") << "\n"; // exception
    cout << "Size: " << map1.size() << "\n";
    cout << map1["ghi"] << "\n";
    cout << "Size: " << map1.size() << "\n";

    // check presence
    if (map1.count("ghi"))
        cout << "ghi is present\n";
    
    // erase
    map1.erase("ghi");
    cout << "Size: " << map1.size() << "\n";
    
    if (map1.count("ghi"))
        cout << "ghi is present\n";
    
    return 0;
}