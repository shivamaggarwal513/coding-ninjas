#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    // vector<int> *vp = new vector<int>;
    for (int i = 0; i < 20; i++)
    {
        cout << "Capacity: " << v.capacity() << ", ";
        cout << "Size: " << v.size() << "\n";
        v.push_back(i + 1);
        cout << "v[" << i << "]: " << v[i] << ", "; // v.at(i)
    }

    // // Don't
    // v[20] = 21;
    // v[21] = 22;

    v.pop_back();
    cout << "\nSize: " << v.size() << "\n";

    return 0;
}