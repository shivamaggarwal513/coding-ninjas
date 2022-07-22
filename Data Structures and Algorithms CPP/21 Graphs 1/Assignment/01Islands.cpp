#include <iostream>
#include <queue>
#include "..\01Graphs.h"
using namespace std;

void _numIslands_Helper(UndirectedGraph &G, int startV, bool *visited)
{
    int curr, i;
    queue<int> q;
    q.push(startV);
    visited[startV] = true;
    while (!q.empty())
    {
        curr = q.front(); q.pop();
        for (i = 0; i < G.nV; i++)
        {
            if (G.edges[curr][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int numIslands(UndirectedGraph &G)
{
    bool *visited = _makeVisitedArray(G.nV);
    int count = 0;
    for (int i = 0; i < G.nV; i++)
    {
        if (!visited[i])
        {
            _numIslands_Helper(G, i, visited);
            count++;
        }
    }
    delete []visited;
    return count;
}

int main()
{
    int nV;
    cin >> nV;
    UndirectedGraph G(nV);
    G.inputEdges();
    cout << numIslands(G) << "\n";
    return 0;
}