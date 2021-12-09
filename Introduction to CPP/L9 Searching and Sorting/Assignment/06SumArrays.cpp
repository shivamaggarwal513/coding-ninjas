#include <iostream>
using namespace std;

void sumArrays(int* &A1, int* &A2, int* &A3, int &n1, int &n2, int &n3)
{
    int i1 = n1 - 1, i2 = n2 - 1, i3 = n3 - 1;
    int c = 0, n;
    while (i1 >= 0 && i2 >= 0)
    {
        n = A1[i1--] + A2[i2--] + c;
        A3[i3--] = n % 10;
        c = n / 10;
    }
    if (i1 < 0)
    {
        while (i2 >= 0)
        {
            n = A2[i2--] + c;
            A3[i3--] = n % 10;
            c = n / 10;
        }
        A3[i3--] = c;
    }
    else
    {
        while (i1 >= 0)
        {
            n = A1[i1--] + c;
            A3[i3--] = n % 10;
            c = n / 10;
        }
        A3[i3--] = c;
    }
}

int main()
{
    int t, n, m, l;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr1 = new int[n];
        for (int i = 0; i < n; i++)
            cin >> arr1[i];
        
        cin >> m;
        int* arr2 = new int[m];
        for (int i = 0; i < m; i++)
            cin >> arr2[i];
        
        l = (m > n) ? (m + 1) : (n + 1);
        int* arr3 = new int[l];
        for (int i = 0; i < l; i++)
            arr3[i] = 0;
        
        sumArrays(arr1, arr2, arr3, n, m, l);

        for (int i = 0; i < l; i++)
            cout << arr3[i] << " ";
        cout << "\n";
    }
    return 0;
}