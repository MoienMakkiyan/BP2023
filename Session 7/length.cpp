#include<iostream>

using namespace std;

int main()
{
    string input;
    getline(cin,input);

    for(int i=0;i<input.length();i++)
    {
        if(input[i]<=90&&input[i]>=65) input[i]+=32;
    }

    cout<<input<<endl;

    return 0;
}
