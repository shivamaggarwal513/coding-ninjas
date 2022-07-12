#include <iostream>
#include <cmath>
using namespace std;

// Brute force (Recursive)
// Time: O(2ⁿ), Space: O(n)
int lootHouses1(int *arr, int n)
{
    if (n <= 0)
        return 0;
    return max(lootHouses1(arr + 1, n - 1), 
            arr[0] + lootHouses1(arr + 2, n - 2));
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int lootHouses2Helper(int *arr, int n, int *prevAns, int currIndex)
{
    if (n <= 0)
        return 0;
    if (prevAns[currIndex] != -1)
        return prevAns[currIndex];
    prevAns[currIndex] = max(lootHouses2Helper(arr + 1, n - 1, prevAns, currIndex + 1), 
                            arr[0] + lootHouses2Helper(arr + 2, n - 2, prevAns, currIndex + 2));
    return prevAns[currIndex];
}

// Memoization (Top-Down Recursive)
// Time: O(n), Space: O(n)
int lootHouses2(int *arr, int n)
{
    int *prevAns = new int[n];
    for (int i = 0; i < n; i++)
        prevAns[i] = -1;
    int ans = lootHouses2Helper(arr, n, prevAns, 0);
    delete []prevAns;
    return ans;
}

// Dynamic Programming (Bottom-Up Iterative)
// Time: O(n), Space: O(n)
int lootHouses3(int *arr, int n)
{
    if (!n)
        return 0;
    int *prevAns = new int[n + 1];
    prevAns[n] = 0, prevAns[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
        prevAns[i] = max(prevAns[i + 1], arr[i] + prevAns[i + 2]);
    int ans = prevAns[0];
    delete []prevAns;
    return ans;
}

// Maximum Optimization
// Time: O(n), Space: O(1)
int lootHouses4(int *arr, int n)
{
    if (!n)
        return 0;
    int prev1 = arr[n - 1], prev2 = 0, curr;
    for (int i = n - 2; i >= 0; i--)
    {
        curr = max(prev1, arr[i] + prev2);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << lootHouses1(arr, n) << " "
        << lootHouses2(arr, n) << " "
        << lootHouses3(arr, n) << " "
        << lootHouses4(arr, n) << "\n";
    delete []arr;
    return 0;
}