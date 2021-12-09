#include <iostream>
#include <string>
using namespace std;

void printStringPermute(string in, string out)
{
    int inSize = in.size();
    if (inSize == 1)
    {
        cout << out + in << "\n";
        return;
    }

    for (int i = 0; i < inSize; i++)
        printStringPermute(in.substr(0, i) + in.substr(i + 1), out + in[i]);
}

int main()
{
    string in;
    cin >> in;
    string out = "";

    printStringPermute(in, out);

    return 0;
}