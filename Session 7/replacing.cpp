#include<iostream>

using namespace std;

int main()
{
    string input;
    string key; /// کلید ما فقط یکبار تکرار شده است
    string new_key;

    getline(cin,input);
    cin>>key;
    cin>>new_key;

    int key_index = input.find(key);

    ///myString.replace(startIndex, length, newString)
    input.replace(key_index,key.length(),new_key);

    cout<<input<<endl;

    return 0;
}
