#include <iostream>
#include "01Graphs.h"
using namespace std;

int main()
{
    int nV, v1, v2;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    cin >> v1 >> v2;
    cout << (G.hasPathDFS(v1, v2) ? "true" : "false") << " "
        << (G.hasPathBFS(v1, v2) ? "true" : "false") << "\n";
    return 0;
}