#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Triplet
{
public:
    int Aij, i, j;

    Triplet() {}
    Triplet(int Aij, int i, int j) : 
    Aij(Aij), i(i), j(j) {}

    void operator=(const Triplet &t)
    {
        Aij = t.Aij;
        i = t.i;
        j = t.j;
    }
};

class greaterComp
{
public:
    bool operator()(const Triplet &left, const Triplet &right)
    { return left.Aij > right.Aij; }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &arrs)
{
    int k = arrs.size(), i, j;
    vector<int> ans;
    priority_queue<Triplet, vector<Triplet>, greaterComp> q;
    for (i = 0; i < k; i++)
        q.push(Triplet(arrs[i][0], i, 0));
    while (!q.empty())
    {
        ans.push_back(q.top().Aij);
        i = q.top().i, j = q.top().j + 1;
        q.pop();
        if (j < arrs[i].size())
            q.push(Triplet(arrs[i][j], i, j));
    }
    return ans;
}

int main()
{
    int k, n, i, j;
    cin >> k;
    vector<vector<int>> arrs(k);
    for (i = 0; i < k; i++)
    {
        cin >> n;
        arrs[i].resize(n);
        for (j = 0; j < n; j++)
            cin >> arrs[i][j];
    }
    vector<int> ans = mergeKSortedArrays(arrs);
    for (int &x: ans)
        cout << x << " ";
    cout << "\n";
    return 0;
}