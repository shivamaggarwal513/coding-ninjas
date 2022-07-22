#include <iostream>
#include <string>
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
int longestComSub1(string s1, string s2)
{
    if (s1.empty() || s2.empty())
        return 0;
    if (s1[0] == s2[0])
        return longestComSub1(s1.substr(1), s2.substr(1)) + 1;
    else
        return max(longestComSub1(s1.substr(1), s2), longestComSub1(s1, s2.substr(1)));
}

// Memoization (Top-Down Recursive)
// Time: O(mn), Space: O(mn)
int longestComSub2Helper(string s1, string s2, int **prevAns)
{
    if (s1.empty() || s2.empty())
        return 0;
    int m = s1.size(), n = s2.size();
    if (prevAns[m][n] != -1)
        return prevAns[m][n];
    if (s1[0] == s2[0])
        prevAns[m][n] = longestComSub2Helper(s1.substr(1), s2.substr(1), prevAns) + 1;
    else
        prevAns[m][n] = max(longestComSub1(s1.substr(1), s2), longestComSub1(s1, s2.substr(1)));
    return prevAns[m][n];
}

// Memoization (Top-Down Recursive)
// Time: O(mn), Space: O(mn)
int longestComSub2(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int **prevAns = _make2DArray(m + 1, n + 1, false, -1);
    int result = longestComSub2Helper(s1, s2, prevAns);
    _delete2DArray(prevAns, m + 1);
    return result;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(mn), Space: O(mn)
int longestComSub3(string s1, string s2)
{
    int m = s1.size(), n = s2.size();
    int **prevAns = _make2DArray(m + 1, n + 1, false, 0);
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            prevAns[i][j] = s1[m - i] == s2[n - j] 
                                ? prevAns[i - 1][j - 1] + 1
                                : max(prevAns[i - 1][j], prevAns[i][j - 1]);
    int result = prevAns[m][n];
    _delete2DArray(prevAns, m + 1);
    return result;
}

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    cout << longestComSub1(s1, s2) << " "
        << longestComSub2(s1, s2) << " "
        << longestComSub3(s1, s2) << "\n";
    return 0;
}