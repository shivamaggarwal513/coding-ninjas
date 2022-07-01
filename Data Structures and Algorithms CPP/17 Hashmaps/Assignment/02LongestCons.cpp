#include <iostream>
#include <unordered_map>
#include <vector>
#include <utility>
using namespace std;

vector<int> longestConsecutive(int *arr, int n)
{
    int len, maxLen = 0, startN, i, j;
    unordered_map<int, pair<int, bool>> mp;
    for (i = 0; i < n; i++)
        mp[arr[i]].first = i, mp[arr[i]].second = false;
    for (i = 0; i < n && !mp[arr[i]].second; i++)
    {
        mp[arr[i]].second = true;
        len = 1;
        for (j = arr[i] + 1; mp.find(j) != mp.end(); j++)
            len++, mp[j].second = true;
        for (j = arr[i] - 1; mp.find(j) != mp.end(); j--)
            len++, mp[j].second = true;
        if (len > maxLen || 
            (len == maxLen && mp[j + 1].first < mp[startN].first))
        {
            startN = j + 1;
            maxLen = len;
        }
    }
    vector<int> ans(1, startN);
    if (maxLen != 1)
        ans.push_back(startN + maxLen - 1);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ans = longestConsecutive(arr, n);
    for (int &x: ans)
        cout << x << " ";
    cout << "\n";
    delete []arr;
    return 0;
}