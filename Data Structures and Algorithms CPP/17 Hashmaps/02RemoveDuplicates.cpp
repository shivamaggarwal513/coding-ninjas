#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

vector<int> removeDuplicates(int *arr, int n)
{
    vector<int> ans;
    unordered_map<int, bool> seenMap;
    for (int i = 0; i < n; i++)
    {
        if (seenMap.find(arr[i]) == seenMap.end())
        {
            ans.push_back(arr[i]);
            seenMap[arr[i]] = true;
        }
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
    vector<int> ans = removeDuplicates(arr, n);
    for (int &v: ans)
        cout << v << " ";
    cout << "\n";
    delete []arr;
    return 0;
}