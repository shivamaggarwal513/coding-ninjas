#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

class MaxPriorityQueue
{
private:
    vector<int> arr;

    int parentChildMax(int &pI)
    {
        int max = pI, lC = 2 * pI + 1, rC = 2 * pI + 2;
        if (lC < arr.size() && arr[lC] > arr[max])
            max = lC;
        if (rC < arr.size() && arr[rC] > arr[max])
            max = rC;
        return max;
    }

public:
    MaxPriorityQueue() {}

    void insert(int val)
    {
        arr.push_back(val);
        int cI = arr.size() - 1, pI = (cI - 1) / 2;
        while (cI > 0 && arr[cI] > arr[pI])
        {
            swap(arr[cI], arr[pI]);
            cI = pI;
            pI = (cI - 1) / 2;
        }
    }

    int removeMax()
    {
        if (arr.empty())
            return INT_MIN;
        int val = arr[0];
        arr[0] = arr[arr.size() - 1];
        arr.pop_back();
        int pI = 0, cI = parentChildMax(pI);
        while (cI != pI)
        {
            swap(arr[pI], arr[cI]);
            pI = cI;
            cI = parentChildMax(pI);
        }
        return val;
    }

    int getMax() { return arr.empty() ? INT_MIN : arr[0]; }

    bool isEmpty() { return arr.empty(); }

    int getSize() { return arr.size(); }
};

int main()
{
    MaxPriorityQueue mxQ;
    for (int i = 1; i <= 10; i++)
        mxQ.insert(i);
    cout << mxQ.getSize() << " " << mxQ.isEmpty() << " " << mxQ.getMax() << "\n";
    while (!mxQ.isEmpty())
        cout << mxQ.removeMax() << " ";
    cout << "\n";
    return 0;
}