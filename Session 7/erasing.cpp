#include<iostream>

using namespace std;

int main()
{
    bool exit = false;

    string output="";
    string input;

    while(!exit)
    {
        cin>>input;
        if(input=="exit")
        {
            exit = true;
            break;
        }

        int pos = input.find("@");
        ///myString.erase(startIndex, length);
        input.erase(pos,input.length()-pos);
        output.append(input);
        output+=" ";

        ///myString.clear();
        input.clear();
    }

    cout<<output<<endl;

    return 0;
}
