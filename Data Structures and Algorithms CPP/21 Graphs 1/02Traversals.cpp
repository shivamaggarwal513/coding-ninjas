#include <iostream>
#include "01Graphs.h"
using namespace std;

int main()
{
    int nV;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    G.printDFS();
    G.printBFS();
    return 0;
}