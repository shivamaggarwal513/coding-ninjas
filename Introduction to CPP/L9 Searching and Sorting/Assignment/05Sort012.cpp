#include <iostream>
using namespace std;

inline void swap(int &a, int &b) { int temp = a; a = b; b = temp; }

void sort012(int* &A, int &n)
{
    int i = 0, nZ = 0, nT = n - 1;
    while (i <= nT)
    {
        if (A[i] == 0)
            swap(A[i++], A[nZ++]);
        else if (A[i] == 1)
            i++;
        else
            swap(A[i], A[nT--]);
    }
}

int main()
{
    int t, n; 
    cin >> t;
    while (t--)
    {
        cin >> n;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> *(arr + i);
        sort012(arr, n);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}