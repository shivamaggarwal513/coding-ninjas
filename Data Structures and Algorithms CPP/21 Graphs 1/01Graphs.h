#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <unordered_map>

bool *_makeVisitedArray(int);

class UndirectedGraph
{
public:
    int nV, nE;
    bool **edges;

private:
    void _printDFS_Helper(int startV, bool *visited)
    {
        std::cout << startV << " ";
        visited[startV] = true;
        for (int i = 0; i < nV; i++)
            if (edges[startV][i] && !visited[i])
                _printDFS_Helper(i, visited);
    }

    void _printBFS_Helper(int startV, bool *visited)
    {
        int curr, i;
        std::queue<int> q;
        q.push(startV);
        visited[startV] = true;
        while (!q.empty())
        {
            curr = q.front(); q.pop();
            std::cout << curr << " ";
            for (i = 0; i < nV; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    bool _hasPathDFS_Helper(int startV, int endV, bool *visited)
    {
        if (edges[startV][endV])
            return true;
        visited[startV] = true;
        for (int i = 0; i < nV; i++)
            if (edges[startV][i] && !visited[i] && _hasPathDFS_Helper(i, endV, visited))
                return true;
        return false;
    }

    bool _hasPathBFS_Helper(int startV, int endV, bool *visited)
    {
        int curr, i;
        std::queue<int> q;
        q.push(startV);
        visited[startV] = true;
        while (!q.empty())
        {
            curr = q.front(); q.pop();
            if (edges[curr][endV])
                return true;
            for (i = 0; i < nV; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return false;
    }

    void _getPathDFS_Helper(int startV, int endV, bool *visited, std::vector<int> &result)
    {
        if (startV == endV)
        {
            result.push_back(endV);
            return;
        }
        visited[startV] = true;
        for (int i = 0; i < nV; i++)
        {
            if (edges[startV][i] && !visited[i])
            {
                _getPathDFS_Helper(i, endV, visited, result);
                if (!result.empty())
                {
                    result.push_back(startV);
                    return;
                }
            }
        }
    }

    void _getPathBFS_Helper(int startV, int endV, bool *visited, std::vector<int> &result)
    {
        int curr, i;
        bool flag = false;
        std::queue<int> q;
        std::unordered_map<int, int> pathMap;
        q.push(startV);
        visited[startV] = true;
        while (!q.empty())
        {
            curr = q.front(); q.pop();
            if (curr == endV)
            {
                flag = true;
                break;
            }
            for (i = 0; i < nV; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    pathMap[i] = curr;
                    visited[i] = true;
                }
            }
        }
        if (flag)
        {
            curr = endV;
            while (curr != startV)
            {
                result.push_back(curr);
                curr = pathMap[curr];
            }
            result.push_back(startV);
        }
    }

    void _isConnected_Helper(bool *visited)
    {
        int curr, i;
        std::queue<int> q;
        q.push(0);
        visited[0] = true;
        while (!q.empty())
        {
            curr = q.front(); q.pop();
            for (i = 0; i < nV; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

    void _getConnectedComp_Helper(int startV, bool *visited, std::vector<int> &result)
    {
        int curr, i;
        std::queue<int> q;
        q.push(startV);
        visited[startV] = true;
        while (!q.empty())
        {
            curr = q.front(); q.pop();
            result.push_back(curr);
            for (i = 0; i < nV; i++)
            {
                if (edges[curr][i] && !visited[i])
                {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
    }

public:
    UndirectedGraph(int nV) : nV(nV)
    {
        edges = new bool*[nV];
        for (int i = 0; i < nV; i++)
        {
            edges[i] = new bool[nV];
            for (int j = 0; j < nV; j++)
                edges[i][j] = false;
        }
    }

    void inputEdges()
    {
        int v1, v2;
        // std::cout << "Enter no. of edges: ";
        std::cin >> nE;
        for (int i = 0; i < nE; i++)
        {
            // std::cout << "Enter edge " << i + 1 << ": ";
            std::cin >> v1 >> v2;
            edges[v1][v2] = edges[v2][v1] = true;
        }
    }

    void printAdjacencyMatrix()
    {
        for (int i = 0; i < nV; i++)
        {
            for (int j = 0; j < nV; j++)
                std::cout << edges[i][j] << " ";
            std::cout << "\n";
        }
    }

    void printDFS()
    {
        bool *visited = _makeVisitedArray(nV);
        // std::cout << "DFS: ";
        for (int i = 0; i < nV; i++)
            if (!visited[i])
                _printDFS_Helper(i, visited);
        std::cout << "\n";
        delete []visited;
    }

    void printBFS()
    {
        bool *visited = _makeVisitedArray(nV);
        // std::cout << "BFS: ";
        for (int i = 0; i < nV; i++)
            if (!visited[i])
                _printBFS_Helper(i, visited);
        std::cout << "\n";
        delete []visited;
    }

    bool hasPathDFS(int startV, int endV)
    {
        bool *visited = _makeVisitedArray(nV);
        bool result = _hasPathDFS_Helper(startV, endV, visited);
        delete []visited;
        return result;
    }

    bool hasPathBFS(int startV, int endV)
    {
        bool *visited = _makeVisitedArray(nV);
        bool result = _hasPathBFS_Helper(startV, endV, visited);
        delete []visited;
        return result;
    }

    std::vector<int> getPathDFS(int startV, int endV)
    {
        bool *visited = _makeVisitedArray(nV);
        std::vector<int> result;
        _getPathDFS_Helper(startV, endV, visited, result);
        delete []visited;
        return result;
    }

    std::vector<int> getPathBFS(int startV, int endV)
    {
        bool *visited = _makeVisitedArray(nV);
        std::vector<int> result;
        _getPathBFS_Helper(startV, endV, visited, result);
        delete []visited;
        return result;
    }

    bool isConnected()
    {
        bool *visited = _makeVisitedArray(nV);
        _isConnected_Helper(visited);
        bool result = true;
        for (int i = 0; i < nV; i++)
        {
            if (!visited[i])
            {
                result = false;
                break;
            }
        }
        delete []visited;
        return result;
    }

    std::vector<std::vector<int>> getConnectedComp()
    {
        bool *visited = _makeVisitedArray(nV);
        std::vector<std::vector<int>> result;
        std::vector<int> comp;
        for (int i = 0; i < nV; i++)
        {
            if (!visited[i])
            {
                _getConnectedComp_Helper(i, visited, comp);
                std::sort(comp.begin(), comp.end());
                result.push_back(comp);
                comp.clear();
            }
        }
        delete []visited;
        return result;
    }

    ~UndirectedGraph()
    {
        for (int i = 0; i < nV; i++)
            delete []edges[i];
        delete []edges;
    }
};

bool *_makeVisitedArray(int nV)
{
    bool *visited = new bool[nV];
    for (int i = 0; i < nV; i++)
        visited[i] = false;
    return visited;
}

/*
Connected Graph Test Case
7 8 0 1 0 2 1 3 1 4 2 6 3 5 4 5 5 6
        0
      /  \
     1    2
    / \    \
   3   4    6
    \  |   /
     \ |  /
       5 -
Disconnected Graph Test Case
10 12 0 1 0 5 1 2 1 3 2 3 3 7 5 7 4 6 4 8 6 8 6 9 8 9
        0       4
      /  \     / \
     1    5   6---8
    / \    \   \ /
   2---3----7   9
*/