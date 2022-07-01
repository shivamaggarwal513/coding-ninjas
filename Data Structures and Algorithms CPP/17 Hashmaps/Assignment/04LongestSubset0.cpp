#include <iostream>
#include <unordered_map>
using namespace std;

int longestSubsetSum(int *arr, int n)
{
    int preSum = 0, len = 0;
    unordered_map<int, int> mp;
    mp[0] = -1;
    for (int i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (mp.find(preSum) != mp.end() && i - mp[preSum] > len)
            len = i - mp[preSum];
        else
            mp[preSum] = i;
    }
    return len;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << longestSubsetSum(arr, n) << "\n";
    delete []arr;
    return 0;
}