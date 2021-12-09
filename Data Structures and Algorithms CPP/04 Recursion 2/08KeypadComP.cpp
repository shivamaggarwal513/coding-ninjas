#include <iostream>
#include <string>
using namespace std;

string key[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

void printKeypadComb(int n, string out)
{
    if (n == 0)
    {
        cout << out << "\n";
        return;
    }

    for (int i = 0; i < key[n % 10].size(); i++)
        printKeypadComb(n / 10, key[n % 10][i] + out);
}

int main()
{
    int n;
    cin >> n;
    string out = "";
    printKeypadComb(n, out);
    return 0;
}