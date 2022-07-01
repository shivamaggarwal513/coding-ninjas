#include <iostream>
#include <unordered_map>
using namespace std;

int pairSumTo0(int *arr, int n)
{
    int ans = 0;
    unordered_map<int, int> freqMap;
    for (int i = 0; i < n; i++)
        freqMap[arr[i]]++;
    for (auto &x: freqMap)
        ans += x.second * freqMap[-x.first];
    return ans / 2;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << pairSumTo0(arr, n) << "\n";
    delete []arr;
    return 0;
}