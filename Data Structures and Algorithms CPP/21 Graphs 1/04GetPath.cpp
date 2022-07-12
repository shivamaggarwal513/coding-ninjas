#include <iostream>
#include <vector>
#include "01Graphs.h"
using namespace std;

int main()
{
    int nV, v1, v2;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    cin >> v1 >> v2;
    vector<int> resDFS = G.getPathDFS(v1, v2);
    for (int &x: resDFS)
        cout << x << " ";
    cout << "\n";
    vector<int> resBFS = G.getPathBFS(v1, v2);
    for (int &x: resBFS)
        cout << x << " ";
    cout << "\n";
    return 0;
}