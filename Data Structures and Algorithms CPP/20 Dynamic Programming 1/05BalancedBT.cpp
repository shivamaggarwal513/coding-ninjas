#include <iostream>
using namespace std;
#define MOD 1000000007

// Brute force (Recursive)
// Time: O(2ⁿ), Space: O(n)
int balancedBT1(int n)
{
    if (n < 2)
        return 1;
    long long int h1 = balancedBT1(n - 1), h2 = balancedBT1(n - 2);
    return (h1 * ((h1 + ((2 * h2) % MOD)) % MOD)) % MOD;
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int balancedBT2Helper(int n, int *arr)
{
    if (n < 2)
        return 1;
    if (arr[n] != -1)
        return arr[n];
    long long int h1 = balancedBT2Helper(n - 1, arr), h2 = balancedBT2Helper(n - 2, arr);
    arr[n] = (h1 * ((h1 + ((2 * h2) % MOD)) % MOD)) % MOD;
    return arr[n];
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int balancedBT2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = balancedBT2Helper(n, arr);
    delete []arr;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n), Space: O(n)
int balancedBT3(int n)
{
    int *arr = new int[n + 1];
    long long int h1, h2;
    arr[0] = 1; arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        h1 = arr[i - 1]; h2 = arr[i - 2];
        arr[i] = (h1 * ((h1 + ((2 * h2) % MOD)) % MOD)) % MOD;
    }
    int ans = arr[n];
    delete []arr;
    return ans;
}

// Maximum Optimization
// Time: O(n), Space: O(1)
int balancedBT4(int n)
{
    if (!n)
        return 1;
    long long int a0 = 1, a1 = 1, a2;
    for (int i = 1; i < n; i++)
    {
        a2 = (a1 * ((a1 + ((2 * a0) % MOD)) % MOD)) % MOD;
        a0 = a1; a1 = a2;
    }
    return a1;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << balancedBT1(n) << " "
            << balancedBT2(n) << " "
            << balancedBT3(n) << " "
            << balancedBT4(n) << "\n";
    }
    return 0;
}