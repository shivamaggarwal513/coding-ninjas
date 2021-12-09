#include <iostream>
using namespace std;

void rotate(int* &A, int &n, int &k)
{
    int i = 0;
    int* tA = new int[k];

    while (i < k)
        tA[i] = A[i++];
    while (i < n)
        A[i - k] = A[i++];
    while (i < n + k)
        A[i - k] = tA[i++ - n];
}

int main()
{
    int t, n, k; 
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int* arr = new int[n];
        for (int i = 0; i < n; i++)
            cin >> *(arr + i);
        rotate(arr, n, k);
        for (int i = 0; i < n; i++)
            cout << *(arr + i) << " ";
        cout << "\n";
    }
    return 0;
}