#include <iostream>
#include <algorithm>
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
// Time: O(2ⁿ), Space: O(n)
int binaryKnapsack1(int n, int *weights, int *values, int maxWeight)
{
    if (!n || !maxWeight)
        return 0;
    if (weights[n - 1] > maxWeight)
        return binaryKnapsack1(n - 1, weights, values, maxWeight);
    return max(binaryKnapsack1(n - 1, weights, values, maxWeight),
                binaryKnapsack1(n - 1, weights, values, maxWeight - weights[n - 1]) + values[n - 1]);
}

// Memoization (Top-Down Recursive)
// Time: O(nW), Space: O(nW)
int binaryKnapsack2Helper(int n, int *weights, int *values, int maxWeight, int **prevAns)
{
    if (!n || !maxWeight)
        return 0;
    if (prevAns[n][maxWeight] != -1)
        return prevAns[n][maxWeight];
    if (weights[n - 1] > maxWeight)
        prevAns[n][maxWeight] = binaryKnapsack2Helper(n - 1, weights, values, maxWeight, prevAns);
    else
        prevAns[n][maxWeight] = max(binaryKnapsack2Helper(n - 1, weights, values, maxWeight, prevAns),
                                    binaryKnapsack2Helper(n - 1, weights, values, maxWeight - weights[n - 1], prevAns) 
                                                            + values[n - 1]);
    return prevAns[n][maxWeight];
}

// Memoization (Top-Down Recursive)
// Time: O(nW), Space: O(nW)
int binaryKnapsack2(int n, int *weights, int *values, int maxWeight)
{
    int **prevAns = _make2DArray(n + 1, maxWeight + 1, false, -1);
    int result = binaryKnapsack2Helper(n, weights, values, maxWeight, prevAns);
    _delete2DArray(prevAns, n + 1);
    return result;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(nW), Space: O(nW)
int binaryKnapsack3(int n, int *weights, int *values, int maxWeight)
{
    int **prevAns = _make2DArray<int>(n + 1, maxWeight + 1);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= maxWeight; j++)
            prevAns[i][j] = weights[i - 1] > j
                                ? prevAns[i - 1][j]
                                : max(prevAns[i - 1][j], prevAns[i - 1][j - weights[i - 1]] + values[i - 1]);
    int result = prevAns[n][maxWeight];
    _delete2DArray(prevAns, n + 1);
    return result;
}

// Maximum Optimization
// Time: O(nW), Space: O(W)
int binaryKnapsack4(int n, int *weights, int *values, int maxWeight)
{
    int **prevAns = _make2DArray<int>(2, maxWeight + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= maxWeight; j++)
            prevAns[1][j] = weights[i - 1] > j
                                ? prevAns[0][j]
                                : max(prevAns[0][j], prevAns[0][j - weights[i - 1]] + values[i - 1]);
        copy(prevAns[1], prevAns[1] + maxWeight + 1, prevAns[0]);
    }
    int result = prevAns[1][maxWeight];
    _delete2DArray(prevAns, 2);
    return result;
}

int main()
{
    int n, maxWeight;
    cin >> n;
    int *weights = new int[n];
    for (int i = 0; i < n; i++)
        cin >> weights[i];
    int *values = new int[n];
    for (int i = 0; i < n; i++)
        cin >> values[i];
    cin >> maxWeight;
    cout << binaryKnapsack1(n, weights, values, maxWeight) << " "
        << binaryKnapsack2(n, weights, values, maxWeight) << " "
        << binaryKnapsack3(n, weights, values, maxWeight) << " "
        << binaryKnapsack4(n, weights, values, maxWeight) << "\n";
    return 0;
}