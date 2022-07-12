#include <iostream>
#include <vector>
#include "01Graphs.h"
using namespace std;

int main()
{
    int nV;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    vector<vector<int>> components = G.getConnectedComp();
    for (vector<int> &v: components)
    {
        for (int &x: v)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}