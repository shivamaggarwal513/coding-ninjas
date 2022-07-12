#include <iostream>
#include <cmath>
using namespace std;

// Brute force (Recursive)
// Time: O(n!), Space: O(n)
int minimumCount1(int n)
{
    if (n < 4)
        return n;
    int minimum = n - 1, rootN = sqrt(n), c;
    for (int i = 1; i <= rootN; i++)
    {
        c = minimumCount1(n - i * i);
        if (c < minimum)
            minimum = c;
    }
    return minimum + 1;
}

// Memoization (Top-Down Recursive)
// Time: O(n√n), Space: O(n)
int minimumCount2Helper(int n, int *arr)
{
    if (n < 4)
        return n;
    if (arr[n] != -1)
        return arr[n];
    int minimum = n - 1, rootN = sqrt(n), c;
    for (int i = 1; i <= rootN; i++)
    {
        c = minimumCount2Helper(n - i * i, arr);
        if (c < minimum)
            minimum = c;
    }
    arr[n] = minimum + 1;
    return arr[n];
}

// Memoization (Top-Down Recursive)
// Time: O(n√n), Space: O(n)
int minimumCount2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = minimumCount2Helper(n, arr);
    delete []arr;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n√n), Space: O(n)
int minimumCount3(int n)
{
    if (n < 4)
        return n;
    int *arr = new int[n + 1], minimum, rootN, c, i, j;
    arr[0] = 0; arr[1] = 1; arr[2] = 2; arr[3] = 3;
    for (i = 4; i <= n; i++)
    {
        minimum = i - 1; rootN = sqrt(i);
        for (j = 1; j <= rootN; j++)
        {
            c = arr[i - j * j];
            if (c < minimum)
                minimum = c;
        }
        arr[i] = minimum + 1;
    }
    int ans = arr[n];
    delete []arr;
    return ans;
}

int main()
{
    int t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        cout << minimumCount1(n) << " "
            << minimumCount2(n) << " "
            << minimumCount3(n) << "\n";
    }
    return 0;
}