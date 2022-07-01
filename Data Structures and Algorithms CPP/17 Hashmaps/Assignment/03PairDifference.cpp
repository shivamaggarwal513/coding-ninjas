#include <iostream>
#include <unordered_map>
using namespace std;

int pairDifferenceK(int *arr, int n, int k)
{
    int ans = 0;
    unordered_map<int, int> freqMap;
    for (int i = 0; i < n; i++)
        freqMap[arr[i]]++;
    if (k)
        for (auto &x: freqMap)
            ans += x.second * (freqMap[x.first + k] + freqMap[x.first - k]);
    else
        for (auto &x: freqMap)
            ans += x.second * (x.second - 1);
    return ans / 2;
}

int main()
{
    int n, k;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    cout << pairDifferenceK(arr, n, k) << "\n";
    delete []arr;
    return 0;
}