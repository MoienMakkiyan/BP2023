#include<iostream>

using namespace std;

int main()
{
    string input = "default";
    while(input!="exit")
    {
        cin>>input;
        cout<<(int)input[0]<<endl;
    }
    return 0;
}
