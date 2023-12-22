#include<iostream>

using namespace std;

int main()
{
    string input;
    cin>>input;

    int pos = 0;

    while(true)
    {
        pos = input.find("b");
        if(pos==-1) break;
        cout<<pos<<endl;// for print b positions
        ///myString.replace(startIndex, length, newString);
        input.replace(pos,1,"-");
    }
    cout<<input<<endl;
    return 0;
}
