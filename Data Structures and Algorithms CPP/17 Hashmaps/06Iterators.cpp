#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main()
{
    unordered_map<char, int> map1 = {{'a', 1}, {'b', 2}, {'c', 3}, {'d', 4}};
    for (unordered_map<char, int>::iterator it = map1.begin(); it != map1.end(); it++)
        cout << it->first << ": " << it->second << "\n";

    vector<int> vec = {1, 2, 3, 4, 5};
    vec.erase(vec.begin() + 3);
    for (vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << "\n";

    return 0;
}