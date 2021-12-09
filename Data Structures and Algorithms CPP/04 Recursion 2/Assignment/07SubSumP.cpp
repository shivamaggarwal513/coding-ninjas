#include <iostream>
using namespace std;

void printSubsetSum(int* in, int n, int* out, int k, int m = 0)
{
    if (n == 0)
    {
        if (k == 0)
        {
            for (int i = 0; i < m; i++)
                cout << out[i] << " ";
            cout << "\n";
        }
        return;
    }
    printSubsetSum(in + 1, n - 1, out, k, m);

    out[m] = in[0];
    printSubsetSum(in + 1, n - 1, out, k - in[0], m + 1);
}

int main()
{
    int n, k;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    
    int* out = new int[n];
    
    printSubsetSum(arr, n, out, k);

    delete []out;
    delete []arr;

    return 0;
}