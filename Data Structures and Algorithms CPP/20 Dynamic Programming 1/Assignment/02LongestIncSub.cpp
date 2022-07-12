#include <iostream>
#include <cmath>
using namespace std;

// Brute force (Recursive)
// Time: O(2ⁿ), Space: O(n)
int longestIncSub1(int *arr, int n, int currIndex = 0, int prevIndex = -1)
{
    if (currIndex == n)
        return 0;
    int maxLen = longestIncSub1(arr, n, currIndex + 1, prevIndex);
    if (prevIndex == -1 || arr[prevIndex] < arr[currIndex])
        maxLen = max(maxLen, 1 + longestIncSub1(arr, n, currIndex + 1, currIndex));
    return maxLen;
}

// Dynamic Programming (Iterative)
// Time: O(n²), Space: O(n)
int longestIncSub2(int *arr, int n)
{
    if (!n)
        return 0;
    int i, j, maxLen = 1;
    int *prevAns = new int[n];
    prevAns[0] = 1;
    for (i = 1; i < n; i++)
    {
        prevAns[i] = 1;
        for (j = 0; j < i; j++)
            if (arr[j] < arr[i])
                prevAns[i] = max(prevAns[i], prevAns[j] + 1);
        maxLen = max(maxLen, prevAns[i]);
    }
    delete []prevAns;
    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestIncSub1(arr, n) << " "
        << longestIncSub2(arr, n) << "\n";
    delete []arr;
    return 0;
}