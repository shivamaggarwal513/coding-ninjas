#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

// Brute force (Recursive)
// Time: O(3ⁿ), Space: O(n)
int minStepsToOne1(int n)
{
    if (n == 1)
        return 0;
    int minimum = minStepsToOne1(n - 1);
    if (n % 2 == 0)
        minimum = min(minimum, minStepsToOne1(n / 2));
    if (n % 3 == 0)
        minimum = min(minimum, minStepsToOne1(n / 3));
    return minimum + 1;
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int minStepsToOne2Helper(int n, int *arr)
{
    if (n == 1)
        return 0;
    if (arr[n] != -1)
        return arr[n];
    int minimum = arr[n - 1] != -1 ? arr[n - 1] : minStepsToOne2Helper(n - 1, arr);
    if (n % 2 == 0)
        minimum = min(minimum, arr[n / 2] != -1 ? arr[n / 2] : minStepsToOne2Helper(n / 2, arr));
    if (n % 3 == 0)
        minimum = min(minimum, arr[n / 3] != -1 ? arr[n / 3] : minStepsToOne2Helper(n / 3, arr));
    arr[n] = minimum + 1;
    return arr[n];
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int minStepsToOne2(int n)
{
    int *arr = new int[n + 1];
    for (int i = 0; i <= n; i++)
        arr[i] = -1;
    int ans = minStepsToOne2Helper(n, arr);
    delete []arr;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n), Space: O(n)
int minStepsToOne3(int n)
{
    if (n == 1)
        return 0;
    int *arr = new int[n + 1];
    arr[1] = 0;
    for (int i = 2; i <= n; i++)
        arr[i] = min(arr[i - 1], 
                min(i % 2 == 0 ? arr[i / 2] : INT_MAX, 
                    i % 3 == 0 ? arr[i / 3] : INT_MAX)) + 1;
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
        cout << minStepsToOne1(n) << " "
            << minStepsToOne2(n) << " "
            << minStepsToOne3(n) << "\n";
    }
    return 0;
}