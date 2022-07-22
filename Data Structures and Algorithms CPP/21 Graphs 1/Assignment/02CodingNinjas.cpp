#include <iostream>
using namespace std;

bool *_makeVisitedArray(int nV)
{
    bool *visited = new bool[nV];
    for (int i = 0; i < nV; i++)
        visited[i] = false;
    return visited;
}

bool hasPath(char **matrix, int n, int m, char *word)
{}

int main()
{
    int n, m, i, j;
    cin >> n >> m;
    char **matrix = new char*[n];
    for (i = 0; i < n; i++)
    {
        matrix[i] = new char[m];
        for (j = 0; j < m; j++)
            cin >> matrix[i][j];
    }
    char word[] = "CODINGNINJA";
    cout << (hasPath(matrix, n, m, word) ? "true" : "false") << "\n";
    return 0;
}