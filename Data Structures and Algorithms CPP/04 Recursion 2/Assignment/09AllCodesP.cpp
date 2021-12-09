#include <iostream>
#include <string>
using namespace std;

void printAllCodes(string in, string out)
{
    if (in.empty())
    {
        cout << out << "\n";
        return;
    }

    int inSize = in.size();

    if (inSize >= 1)
    {
        char in0 = 96 + stoi(in.substr(0, 1));
        printAllCodes(in.substr(1), out + in0);
    }
    if (inSize >= 2)
    {
        char in01 = 96 + stoi(in.substr(0, 2));
        if (in01 > 'z')
            return;
        printAllCodes(in.substr(2), out + in01);
    }
}

int main()
{
    string in, out = "";
    cin >> in;
    printAllCodes(in, out);
    return 0;
}