#include <iostream>
using namespace std;

// Brute force (Recursive)
// Time: O(3ⁿ), Space: O(n)
int staircase1(int n)
{
    if (n < 3)
        return n ? n : 1;
    return staircase1(n - 1) + staircase1(n - 2) + staircase1(n - 3);
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int staircase2Helper(int n, int *arr)
{
    if (n < 3)
        return n ? n : 1;
    if (arr[n] != -1)
        return arr[n];
    arr[n] = staircase2Helper(n - 1, arr) + 
            staircase2Helper(n - 2, arr) + 
            staircase2Helper(n - 3, arr);
    return arr[n];
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int staircase2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = staircase2Helper(n, arr);
    delete []arr;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n), Space: O(n)
int staircase3(int n)
{
    if (n < 2)
        return 1;
    int *arr = new int[n + 1];
    arr[0] = 1; arr[1] = 1; arr[2] = 2;
    for (int i = 3; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
    int ans = arr[n];
    delete []arr;
    return ans;
}

// Maximum Optimization
// Time: O(n), Space: O(1)
int staircase4(int n)
{
    if (n < 2)
        return 1;
    int a0 = 1, a1 = 1, a2 = 2, a3;
    for (int i = 2; i < n; i++)
    {
        a3 = a2 + a1 + a0;
        a0 = a1; a1 = a2; a2 = a3;
    }
    return a2;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << staircase1(n) << " "
            << staircase2(n) << " "
            << staircase3(n) << " "
            << staircase4(n) << "\n";
    }
    return 0;
}