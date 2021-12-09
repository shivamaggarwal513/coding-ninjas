#include <iostream>
using namespace std;

void printSubsetArray(int* in, int n, int* out, int m = 0)
{
    if (n == 0)
    {
        for (int i = 0; i < m; i++)
            cout << out[i] << " ";
        cout << "\n";
        return;
    }
    printSubsetArray(in + 1, n - 1, out, m);

    out[m] = in[0];
    printSubsetArray(in + 1, n - 1, out, m + 1);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    int* out = new int[n];
    
    printSubsetArray(arr, n, out);

    delete []out;
    delete []arr;

    return 0;
}