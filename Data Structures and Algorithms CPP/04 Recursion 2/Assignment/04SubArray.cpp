#include <iostream>
#include <cmath>
using namespace std;

int subsetArray(int* in, int n, int** out)
{
    if (n == 0)
    {
        out[0][0] = 0;
        return 1;
    }
    int recSize = subsetArray(in + 1, n - 1, out);
    for (int i = 0; i < recSize; i++)
    {
        out[recSize + i][0] = 1 + out[i][0];
        out[recSize + i][1] = in[0];

        for (int j = 1; j <= out[i][0]; j++)
            out[recSize + i][j + 1] = out[i][j];
    }
    return 2 * recSize;
}

int main()
{
    int n, size;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    size = pow(2, n);
    int** out = new int*[size];
    for (int i = 0; i < size; i++)
        out[i] = new int[n + 1];
    
    size = subsetArray(arr, n, out);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= out[i][0]; j++)
            cout << out[i][j] << " ";
        cout << "\n";
    }

    for (int i = 0; i < size; i++)
        delete []out[i];
    delete []out;
    delete []arr;

    return 0;
}