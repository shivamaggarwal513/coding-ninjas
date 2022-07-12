#include <iostream>
using namespace std;

// Brute force (Recursive)
// Time: O(2ⁿ), Space: O(n)
int fibonacciN1(int n)
{
    if (n < 2)
        return n;
    return fibonacciN1(n - 1) + fibonacciN1(n - 2);
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int fibonacciN2Helper(int n, int *arr)
{
    if (n < 2)
        return n;
    if (arr[n] != -1)
        return arr[n];
    arr[n] = fibonacciN2Helper(n - 1, arr) + fibonacciN2Helper(n - 2, arr);
    return arr[n];
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int fibonacciN2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = fibonacciN2Helper(n, arr);
    delete []arr;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n), Space: O(n)
int fibonacciN3(int n)
{
    int *arr = new int[n + 1];
    arr[0] = 0; arr[1] = 1;
    for (int i = 2; i <= n; i++)
        arr[i] = arr[i - 1] + arr[i - 2];
    int ans = arr[n];
    delete []arr;
    return ans;
}

// Maximum Optimization
// Time: O(n), Space: O(1)
int fibonacciN4(int n)
{
    if (!n)
        return 0;
    int a0 = 0, a1 = 1, a2;
    for (int i = 1; i < n; i++)
    {
        a2 = a1 + a0;
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
        cout << fibonacciN1(n) << " "
            << fibonacciN2(n) << " "
            << fibonacciN3(n) << " "
            << fibonacciN4(n) << "\n";
    }
    return 0;
}