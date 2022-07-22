#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

template <typename T>
T **_make2DArray(int row, int col, bool takeInput = false, T val = 0)
{
    T **result = new T*[row];
    for (int i = 0; i < row; i++)
    {
        result[i] = new T[col];
        for (int j = 0; j < col; j++)
        {
            if (takeInput)
                std::cin >> val;
            result[i][j] = val;
        }
    }
    return result;
}

template <typename T>
void _delete2DArray(T **matrix, int row)
{
    for (int i = 0; i < row; i++)
        delete []matrix[i];
    delete []matrix;
}

// Brute force (Recursive)
// Time: O(3ᵐ⁺ⁿ), Space: O(m + n)
int minCostPath1(int **matrix, int m, int n, int row = 0, int col = 0)
{
    if (row == m - 1 && col == n - 1)
        return matrix[row][col];
    if (row >= m || col >= n)
        return INT_MAX;
    return matrix[row][col] + min(minCostPath1(matrix, m, n, row + 1, col),
                                min(minCostPath1(matrix, m, n, row, col + 1),
                                minCostPath1(matrix, m, n, row + 1, col + 1)));
}

// Memoization (Top-Down Recursive)
// Time: O(mn), Space: O(mn)
int minCostPath2Helper(int **matrix, int m, int n, int row, int col, int **prevAns)
{
    if (row == m - 1 && col == n - 1)
        return matrix[row][col];
    if (row >= m || col >= n)
        return INT_MAX;
    if (prevAns[row][col] != INT_MIN)
        return prevAns[row][col];
    prevAns[row][col] = matrix[row][col] + min(minCostPath2Helper(matrix, m, n, row + 1, col, prevAns),
                                            min(minCostPath2Helper(matrix, m, n, row, col + 1, prevAns),
                                            minCostPath2Helper(matrix, m, n, row + 1, col + 1, prevAns)));
    return prevAns[row][col];
}

// Memoization (Top-Down Recursive)
// Time: O(mn), Space: O(mn)
int minCostPath2(int **matrix, int m, int n)
{
    int **prevAns = _make2DArray(m, n, false, INT_MIN);
    int result = minCostPath2Helper(matrix, m, n, 0, 0, prevAns);
    _delete2DArray(prevAns, m);
    return result;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(mn), Space: O(mn)
int minCostPath3(int **matrix, int m, int n)
{
    int **prevAns = _make2DArray(m + 1, n + 1, false, INT_MAX);
    prevAns[m][n] = 0;
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
            prevAns[i][j] = matrix[i][j] + min(prevAns[i + 1][j + 1], min(prevAns[i + 1][j], prevAns[i][j + 1]));
    int result = prevAns[0][0];
    _delete2DArray(prevAns, m + 1);
    return result;
}

int main()
{
    int m, n;
    cin >> m >> n;
    int **matrix = _make2DArray<int>(m, n, true);
    cout << minCostPath1(matrix, m, n) << " "
        << minCostPath2(matrix, m, n) << " "
        << minCostPath3(matrix, m, n) << "\n";
    _delete2DArray(matrix, m);
    return 0;
}