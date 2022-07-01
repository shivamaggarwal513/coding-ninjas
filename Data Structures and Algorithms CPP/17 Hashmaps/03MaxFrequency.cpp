#include <iostream>
#include <unordered_map>
using namespace std;

int maximumFrequency(int *arr, int n)
{
    int ans = arr[n - 1];
    unordered_map<int, int> freqMap;
    freqMap[arr[n - 1]] = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        freqMap[arr[i]]++;
        if (freqMap[arr[i]] >= freqMap[ans])
            ans = arr[i];
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maximumFrequency(arr, n) << "\n";
    delete []arr;
    return 0;
}