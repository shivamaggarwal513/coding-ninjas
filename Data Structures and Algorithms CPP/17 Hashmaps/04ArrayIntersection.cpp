#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

void printIntersection(int *arr1, int n, int *arr2, int m)
{
    unordered_map<int, int> arr2freq;
    vector<int> intersection;
    for (int i = 0; i < m; i++)
        arr2freq[arr2[i]]++;
    for (int i = 0; i < n; i++)
    {
        if (arr2freq[arr1[i]] > 0)
        {
            intersection.push_back(arr1[i]);
            arr2freq[arr1[i]]--;
        }
    }
    sort(intersection.begin(), intersection.end());
    for (int &num: intersection)
        cout << num << " ";
    cout << "\n";
}

int main()
{
    int t, n, m, i;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int *arr1 = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr1[i];
        cin >> m;
        int *arr2 = new int[m];
        for (i = 0; i < m; i++)
            cin >> arr2[i];
        printIntersection(arr1, n, arr2, m);
        delete []arr1;
        delete []arr2;
    }
    return 0;
}