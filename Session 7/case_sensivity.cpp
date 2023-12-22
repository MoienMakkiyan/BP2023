#include<iostream>

using namespace std;

int main()
{
    string a = "Apple";
    string b = "apple";
    string c = "Apple ";

    cout<<(bool)(a==b)<<endl;
    cout<<(bool)(a==c)<<endl;
    return 0;
}
