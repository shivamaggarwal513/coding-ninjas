#include <iostream>
#include <string>
using namespace std;

void printSubSequences(string in, string out)
{
    if (in.empty())
    {
        cout << out << "\n";
        return;
    }
    printSubSequences(in.substr(1), out);
    printSubSequences(in.substr(1), out + in[0]);
}

int main()
{
    string in;
    cin >> in;
    string out = "";
    printSubSequences(in, out);
    return 0;
}