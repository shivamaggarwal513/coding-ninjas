#include <iostream>
using namespace std;

int search(int* arr, int n, int x, int* out)
{
    // int ans = 0;
    // if (n == 0)
    //     return 0;
    // if (arr[0] == x)
    // {
    //     out[0] = 0;
    //     ans += 1 + search(arr + 1, n - 1, x, out + 1);
    //     for (int i = 1; i < ans; i++)
    //         out[i]++;
    // }
    // else
    // {
    //     ans += search(arr + 1, n - 1, x, out);
    //     for (int i = 0; i < ans; i++)
    //         out[i]++;
    // }
    // return ans;

    int ans = 0, i = 0;
    if (n == 0)
        return 0;
    if (arr[0] == x)
        out[i++] = 0;
    ans += i + search(arr + 1, n - 1, x, out + i);
    for (; i < ans; i++)
        out[i]++;
    return ans;
}

int main()
{
    int n, x;
    cin >> n;
    int* arr = new int[n];
    int* out = new int[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> x;
    int s = search(arr, n, x, out);
    for (int i = 0; i < s; i++)
        cout << out[i] << " ";
    cout << "\n";
    return 0;
}