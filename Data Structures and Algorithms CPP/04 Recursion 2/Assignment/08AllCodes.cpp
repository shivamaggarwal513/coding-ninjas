#include <iostream>
#include <string>
using namespace std;

int allCodes(string in, string* out)
{
    int inSize = in.size();
    if (inSize == 1)
    {
        out[0] = 96 + stoi(in);
        return 1;
    }
    
    int i, recSize1 = 0, recSize2 = 0;

    if (inSize > 1)
    {
        char in0 = 96 + stoi(in.substr(0, 1));
        string recOut1[10];
        recSize1 = allCodes(in.substr(1), recOut1);
        for (i = 0; i < recSize1; i++)
            out[i] = in0 + recOut1[i];
        
        if (inSize == 2)
        {
            char c = 96 + stoi(in);
            if (c > 'z')
                return recSize1;
            out[i] = 96 + stoi(in);
            return recSize1 + 1;
        }
    }

    if (inSize > 2)
    {
        char in01 = 96 + stoi(in.substr(0, 2));
        if (in01 > 'z')
            return recSize1;
        string recOut2[10];
        recSize2 = allCodes(in.substr(2), recOut2);
        for (i = recSize1; i < recSize1 + recSize2; i++)
            out[i] = in01 + recOut2[i - recSize1];
    }
    return recSize1 + recSize2;
}

int main()
{
    string in, out[10];
    cin >> in;
    int size = allCodes(in, out);
    for (int i = 0; i < size; i++)
        cout << out[i] << "\n";
    return 0;
}