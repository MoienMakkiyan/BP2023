#include<iostream>

using namespace std;

int main()
{
    string input;
    string key;

    getline(cin,input);
    cin>>key;

    ///int position = myString.find(subString);
    int isFind = input.find(key);
    cout<<isFind<<endl; /// will return first index of key;
    cout<<input.substr(isFind)<<endl; /// will print rest of the input!

    return 0;
}
