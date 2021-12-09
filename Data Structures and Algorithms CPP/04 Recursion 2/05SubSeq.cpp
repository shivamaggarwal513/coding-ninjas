#include <iostream>
#include <cmath>
#include <string>
using namespace std;

int subSequences(string in, string* out)
{
    if (in.empty())
    {
        out[0] = "";
        return 1;
    }
    int recSize = subSequences(in.substr(1), out);
    for (int i = 0; i < recSize; i++)
        out[recSize + i] = in[0] + out[i];
    return 2 * recSize;
}

int main()
{
    string s;
    cin >> s;
    string* out = new string[(int)pow(2, s.size())];
    int n = subSequences(s, out);
    for (int i = 0; i < n; i++)
        cout << out[i] << "\n";
    return 0;
}