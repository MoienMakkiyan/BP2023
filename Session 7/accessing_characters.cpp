#include<iostream>

using namespace std;

int main()
{
    string input = "I love CPP!!!";
    cout<<input<<endl;

    ///char letter = myString[index];
    input[2] = 'h';
    input[3] = 'a';
    input[4] = 't';
    input[5] = 'e';

    cout<<input<<endl;

    return 0;
}

