#include <iostream>
#include <string>
using namespace std;

int fact(int n) { return n == 0 ? 1 : n * fact(n - 1); }

int stringPermute(string in, string* out)
{
    int inSize = in.size();
    if (inSize == 0)
    {
        out[0] = "";
        return 1;
    }
    
    string* recOut = new string[fact(inSize - 1)];
    int recSize = stringPermute(in.substr(1), recOut);

    for (int i = 0; i < recSize; i++)
        for (int j = 0; j < inSize; j++)
            out[i * inSize + j] = recOut[i].substr(0, j) + in[0] + recOut[i].substr(j);
    
    return inSize * recSize;
}

int main()
{
    string in;
    cin >> in;
    string* out = new string[fact(in.size())];

    int size = stringPermute(in, out);

    for (int i = 0; i < size; i++)
        cout << out[i] << "\n";
    
    delete []out;

    return 0;
}