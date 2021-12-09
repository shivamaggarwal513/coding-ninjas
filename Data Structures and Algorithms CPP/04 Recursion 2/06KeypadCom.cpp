#include <iostream>
#include <string>
using namespace std;

string key[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

int keypadComb(int n, string* out)
{
    if (n == 0)
    {
        out[0] = "";
        return 1;
    }
    int recSize = keypadComb(n / 10, out);

    for (int i = 1; i < key[n % 10].size(); i++)
        for (int j = 0; j < recSize; j++)
            out[recSize * i + j] = out[j] + key[n % 10][i];

    for (int j = 0; j < recSize; j++)
        out[j] += key[n % 10][0];
    
    return key[n % 10].size() * recSize;
}

int main()
{
    int n;
    cin >> n;

    string* out = new string[1000];
    int size = keypadComb(n, out);

    for (int i = 0; i < size; i++)
        cout << out[i] << "\n";
    
    return 0;
}