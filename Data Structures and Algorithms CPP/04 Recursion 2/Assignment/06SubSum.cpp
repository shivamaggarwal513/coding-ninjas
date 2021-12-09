#include <iostream>
using namespace std;

int subsetSum(int* in, int n, int out[][10], int k)
{
    if (n == 0)
    {
        if (k == 0)
        {
            out[0][0] = 0;
            return 1;
        }
        return 0;
    }
    int recOut1[10][10], recOut2[10][10];

    int recSize1 = subsetSum(in + 1, n - 1, recOut1, k);
    int recSize2 = subsetSum(in + 1, n - 1, recOut2, k - in[0]);

    for (int i = 0; i < recSize1; i++)
        for (int j = 0; j <= recOut1[i][0]; j++)
            out[i][j] = recOut1[i][j];
    
    for (int i = recSize1; i < recSize1 + recSize2; i++)
    {
        out[i][0] = recOut2[i - recSize1][0] + 1;
        out[i][1] = in[0];
        for (int j = 1; j <= recOut2[i - recSize1][0]; j++)
            out[i][j + 1] = recOut2[i - recSize1][j];
    }

    return recSize1 + recSize2;
}

int main()
{
    int n, k, arr[10], out[10][10];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    
    int size = subsetSum(arr, n, out, k);

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j <= out[i][0]; j++)
            cout << out[i][j] << " ";
        cout << "\n";
    }

    return 0;
}