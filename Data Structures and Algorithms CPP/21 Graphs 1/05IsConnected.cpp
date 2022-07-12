#include <iostream>
#include "01Graphs.h"
using namespace std;

int main()
{
    int nV;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    cout << (G.isConnected() ? "true" : "false") << "\n";
    return 0;
}