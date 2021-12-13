#include <iostream>
#include <algorithm>
using namespace std;

void intersectionArr(int* A1, int n1, int* A2, int n2)
{
    int i1 = 0, i2 = 0;
    sort(A1, A1 + n1);
    sort(A2, A2 + n2);
    while (i1 < n1 && i2 < n2)
    {
        if (A1[i1] == A2[i2])
        {
            cout << A1[i1] << " ";
            i1++; i2++;
        }
        else if (A1[i1] <= A2[i2])
            i1++;
        else
            i2++;
    }
    cout << "\n";
}

int main()
{
    int t, n, m, i, l;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr1 = new int[n];
        for (i = 0; i < n; i++)
            cin >> arr1[i];
        
        cin >> m;
        int* arr2 = new int[m];
        for (i = 0; i < m; i++)
            cin >> arr2[i];
        
        intersectionArr(arr1, n, arr2, m);
        
        delete []arr1;
        delete []arr2;
    }
    return 0;
}