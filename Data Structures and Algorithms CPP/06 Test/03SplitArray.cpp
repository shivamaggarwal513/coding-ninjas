#include <iostream>
using namespace std;

bool splitArray(int* A, int n, int i = 0, int sum1 = 0, int sum2 = 0)
{
    if (i == n)
        return sum1 == sum2;
    
    if (A[i] % 5 == 0)
        sum1 += A[i];
    else if (A[i] % 3 == 0)
        sum2 += A[i];
    else
        return splitArray(A, n, i + 1, sum1 + A[i], sum2) || splitArray(A, n, i + 1, sum1, sum2 + A[i]);
    
    return splitArray(A, n, i + 1, sum1, sum2);
}

int main()
{
    int n;
    cin >> n;
    int* arr = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << (splitArray(arr, n) ? "true" : "false") << "\n";
    return 0;
}